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

PeyoteTab *peyote_tab_new()
{
   PeyoteTab *new ;
   new = malloc (sizeof(PeyoteTab)) ;
   return new ;
}

int peyote_tab_initialize()
{
   peyote->peyote_tab->text_buffer = GTK_TEXT_BUFFER(gtk_builder_get_object(
     peyote->peyote_window->builder, "peyote_text_buffer")) ;
   return 0 ;
}

int peyote_tab_read_file(char *filepath)
{
   long text_buffer_size ;

   peyote->peyote_tab->file = fopen(filepath, "r+") ;
   if (peyote->peyote_tab->file == NULL)
      fprintf (stderr, "PEYOTE ERROR: failed to open file") ;

   fseek(peyote->peyote_tab->file, 0L, SEEK_END) ;
   text_buffer_size = ftell(peyote->peyote_tab->file) ;
   peyote->peyote_tab->content = calloc(text_buffer_size, sizeof(char)) ;
   rewind(peyote->peyote_tab->file) ;
   fread(peyote->peyote_tab->content, sizeof(char), text_buffer_size, peyote->peyote_tab->file) ;
   fclose(peyote->peyote_tab->file) ;

   gtk_text_buffer_set_text(peyote->peyote_tab->text_buffer, peyote->peyote_tab->content, -1) ;

   return 0 ;
}
