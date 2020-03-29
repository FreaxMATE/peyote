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

#include "peyote-tab.h"

char *peyote_tab_get_metadata_value_from_key(char *content, char *key) ;
char *peyote_tab_get_tab(char *content) ;

PeyoteTab *peyote_tab_new()
{
   PeyoteTab *new ;
   new = malloc (sizeof(PeyoteTab)) ;
   return new ;
}

int peyote_tab_initialize(char *path)
{
   peyote->tab->tab_text = GTK_TEXT_BUFFER(gtk_builder_get_object(
     peyote->window->builder, "peyote_tab_text")) ;
   if (strcmp(path, "NOFILE"))
      peyote_tab_read_file(path) ;
   return 0 ;
}

int peyote_tab_read_file(char *filepath)
{
   char *content ;
   if (!g_file_get_contents(filepath, &content, NULL, NULL))
      fprintf (stderr, "Peyote ERROR: Could not get content of file %s\n", filepath) ;

   peyote->tab->artist = peyote_tab_get_metadata_value_from_key(content, "Artist") ;
   peyote->tab->song = peyote_tab_get_metadata_value_from_key(content, "Song") ;
   peyote->tab->album = peyote_tab_get_metadata_value_from_key(content, "Album") ;
   peyote->tab->tabs = peyote_tab_get_tab(content) ;
   peyote_window_set_window_title(g_strdup_printf("Peyote - %s by %s", peyote->tab->song, peyote->tab->artist)) ;
   gtk_text_buffer_set_text(peyote->tab->tab_text, peyote->tab->tabs, -1) ;
   g_free(content) ;
   return 0 ;
}

char *peyote_tab_get_tab(char *content)
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

char *peyote_tab_get_metadata_value_from_key(char *content, char *key)
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

void peyote_tab_make_pdf()
{
   return ;
}

