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
char *peyote_file_parser_make_file_content(void) ;

PeyoteFileParser *peyote_file_parser_new()
{
   PeyoteFileParser *new ;
   new = malloc (sizeof(PeyoteFileParser)) ;
   return new ;
}

int peyote_file_parser_initialize(char *path)
{
   peyote->parser->tab_text = GTK_TEXT_BUFFER(gtk_builder_get_object(
     peyote->window->builder, "peyote_tab_text")) ;
   peyote->parser->tabs = NULL ;
   peyote->parser->artist = NULL ;
   peyote->parser->song = NULL ;
   peyote->parser->album = NULL ;

   if (strcmp(path, "NOFILE"))
      peyote_file_parser_read_file(path) ;
   return 0 ;
}

int peyote_file_parser_read_file(char *filepath)
{
   char *content ;
   if (!g_file_get_contents(filepath, &content, NULL, NULL))
      fprintf (stderr, "Peyote ERROR: Could not get content of file %s\n", filepath) ;
   peyote->filepath = g_strdup(filepath) ;
   peyote->parser->artist = peyote_file_parser_get_metadata_value_from_key(content, "Artist") ;
   peyote->parser->song = peyote_file_parser_get_metadata_value_from_key(content, "Song") ;
   peyote->parser->album = peyote_file_parser_get_metadata_value_from_key(content, "Album") ;
   peyote->parser->tabs = peyote_file_parser_get_tabs(content) ;
   peyote_window_set_window_title(g_strdup_printf("Peyote - %s by %s", peyote->parser->song, peyote->parser->artist)) ;
   gtk_text_buffer_set_text(peyote->parser->tab_text, peyote->parser->tabs, -1) ;
   g_free(content) ;
   return 0 ;
}

void peyote_file_parser_save_file(char *filepath)
{
   g_file_set_contents(filepath, peyote_file_parser_make_file_content(), -1, NULL) ;
   return ;
}

char *peyote_file_parser_make_file_content()
{
   GtkTextIter start, end ;
   gtk_text_buffer_get_bounds(peyote->parser->tab_text, &start, &end) ;
   return g_strdup_printf("[metadata]\nArtist=%s\nSong=%s\nAlbum=%s\n[tabs]\n%s",
                          peyote->parser->artist, peyote->parser->song, peyote->parser->album,
                          gtk_text_buffer_get_text(peyote->parser->tab_text, &start, &end, FALSE)) ;
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
   char *p ;
   p = g_strrstr(content, g_strjoin(NULL, key, "=", NULL)) ;
   p = &p[(strlen(key)+1)*sizeof(char)] ;
   char *startp = p ;
   int n = 0 ;
   while (p[n] != '\n' && p[n] != 0)
      ++n ;
   return g_strndup(startp, n*sizeof(char)) ;
}

