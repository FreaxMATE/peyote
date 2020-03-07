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

#include "peyote-window.h"

PeyoteWindow *peyote_window_new()
{
   PeyoteWindow *new ;
   new = malloc (sizeof(PeyoteWindow)) ;
   return new ;
}

int peyote_window_initialize()
{
   if (!access("/usr/local/share/peyote/org.github.FreaxMATE.peyote.glade", F_OK))
      peyote->peyote_window->builder = gtk_builder_new_from_file(
        "/usr/local/share/peyote/org.github.FreaxMATE.peyote.glade") ;
   else
      peyote->peyote_window->builder = gtk_builder_new_from_file(
        "../data/org.github.FreaxMATE.peyote.glade") ;

   gtk_builder_connect_signals(peyote->peyote_window->builder, NULL) ;
   peyote->peyote_window->window = GTK_WINDOW(gtk_builder_get_object(
     peyote->peyote_window->builder, "peyote_window")) ;
   gtk_widget_show(GTK_WIDGET(peyote->peyote_window->window)) ;

   return 0 ;
}

void on_peyote_window_destroy()
{
   gtk_main_quit() ;
}

