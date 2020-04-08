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

#include "peyote-file.h"

PeyoteFile *peyote_file_new()
{
   PeyoteFile *new ;
   new = malloc(sizeof(PeyoteFile)) ;
   return new ;
}

void peyote_file_initialize(PeyoteFile *file, char *filepath)
{
   char *filename ;
   if (!(filepath == NULL))
   {
      file->path = g_strdup(filepath) ;
      filename = g_path_get_basename(filepath) ;
   }
   else
   {
      filename = g_strdup("New File") ;
   }
   file->tab_label = GTK_LABEL(gtk_label_new(filename)) ;

   file->scroll = GTK_SCROLLED_WINDOW(gtk_scrolled_window_new(NULL, NULL)) ;
   file->text_buffer = gtk_text_buffer_new(NULL) ;
   file->text_view = GTK_TEXT_VIEW(gtk_text_view_new_with_buffer(file->text_buffer)) ;
   file->parser = peyote_file_parser_new() ;
   peyote_file_parser_initialize(file, file->parser, file->text_buffer, filepath) ;

   gtk_container_add(GTK_CONTAINER(file->scroll), GTK_WIDGET(file->text_view)) ;
   gtk_notebook_append_page(peyote->window->notebook, GTK_WIDGET(file->scroll), GTK_WIDGET(file->tab_label)) ;
   gtk_widget_show_all(GTK_WIDGET(peyote->window->notebook)) ;
   gtk_notebook_set_current_page(peyote->window->notebook, peyote->files->n-1) ;
   g_free(filename) ;
   return ;
}


