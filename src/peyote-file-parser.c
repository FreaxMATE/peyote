/*
 * Copyright (c) 2019 FreaxMATE
 *
 * This file is part of Peyote.
 *
 * Peyote is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Peyote is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Peyote.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "peyote-file-parser.h"

char *peyote_file_parser_get_metadata_value_from_key(char *content, char *key) ;
char *peyote_file_parser_get_tabs(char *content) ;
char *peyote_file_parser_make_file_content(PeyoteFileParser *parser) ;

PeyoteFileParser *peyote_file_parser_new()
{
   PeyoteFileParser *new ;
   new = malloc (sizeof(PeyoteFileParser)) ;
   return new ;
}

int peyote_file_parser_initialize(PeyoteFile *file, PeyoteFileParser *parser, GtkTextBuffer *text_buffer, char *filepath)
{
   parser->file = file ;
   parser->tabs = NULL ;
   parser->artist = NULL ;
   parser->song = NULL ;
   parser->album = NULL ;

   if (strcmp(filepath, "NOFILE"))
      peyote_file_parser_read_file(parser) ;
   return 0 ;
}

int peyote_file_parser_read_file(PeyoteFileParser *parser)
{
   char *content, *new_title ;
   if (!g_file_get_contents(parser->file->path, &content, NULL, NULL))
      fprintf (stderr, "Peyote ERROR: Could not get content of file %s\n", parser->file->path) ;
   parser->artist = peyote_file_parser_get_metadata_value_from_key(content, "Artist") ;
   parser->song = peyote_file_parser_get_metadata_value_from_key(content, "Song") ;
   parser->album = peyote_file_parser_get_metadata_value_from_key(content, "Album") ;
   parser->tabs = peyote_file_parser_get_tabs(content) ;
   new_title = g_strdup_printf("Peyote - %s by %s", parser->song, parser->artist) ;
   peyote_window_set_window_title(new_title) ;
   gtk_text_buffer_set_text(parser->file->text_buffer, parser->tabs, -1) ;
   g_free(new_title) ;
   g_free(content) ;
   return 0 ;
}

void peyote_file_parser_save_file(char *filepath)
{
   g_file_set_contents(filepath, peyote_file_parser_make_file_content(peyote->files->current->parser), -1, NULL) ;
   return ;
}

char *peyote_file_parser_make_file_content(PeyoteFileParser *parser)
{
   GtkTextIter start, end ;
   gtk_text_buffer_get_bounds(parser->file->text_buffer, &start, &end) ;
   return g_strdup_printf("[metadata]\nArtist=%s\nSong=%s\nAlbum=%s\n[tabs]\n%s",
                          parser->artist, parser->song, parser->album,
                          gtk_text_buffer_get_text(parser->file->text_buffer, &start, &end, FALSE)) ;
}

char *peyote_file_parser_get_tabs(char *content)
{
   char *p ;
   p = g_strrstr(content, "[tabs]") ;
   p = &p[(strlen("[tabs]")+1)*sizeof(char)] ;
   char *startp = p ;
   int n = 0 ;
   while (p[n] != 0)
   {
      if (n != 0 && p[n] == '\n' && p[n-1] == '\n')
         break ;
      ++n ;
   }
   return g_strndup(startp, n*sizeof(char)) ;
}

char *peyote_file_parser_get_metadata_value_from_key(char *content, char *key)
{
   char *search_string ;
   char *p ;
   search_string = g_strjoin(NULL, key, "=", NULL) ;
   p = g_strrstr(content, search_string) ;
   if (p == NULL)
      return g_strdup("Unknown") ;
   p = &p[(strlen(key)+1)*sizeof(char)] ;
   char *startp = p ;
   int n = 0 ;
   while (p[n] != '\n' && p[n] != 0)
      ++n ;
   g_free(search_string) ;
   return g_strndup(startp, n*sizeof(char)) ;
}

