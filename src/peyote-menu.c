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

#include "peyote-menu.h"

PeyoteMenu *peyote_menu_new()
{
   PeyoteMenu *new ;
   new = malloc(sizeof(PeyoteMenu)) ;
   return new ;
}

int peyote_menu_initialize()
{
   peyote->peyote_menu->peyote_menu_open = GTK_IMAGE_MENU_ITEM(
     gtk_builder_get_object(peyote->peyote_window->builder, "peyote_menu_open")) ;
   peyote->peyote_menu->peyote_menu_quit = GTK_IMAGE_MENU_ITEM(
     gtk_builder_get_object(peyote->peyote_window->builder, "peyote_menu_quit")) ;

   return 0 ;
}


/* Callbacks */

void on_peyote_menu_open_activate()
{
   char *filepath ;

   if ((filepath = peyote_filechooser_open_file()) != NULL)
   {
      peyote_tab_read_file(filepath) ;
      return ;
   }
   fprintf (stderr, "PEYOTE WARNING: filechooser returned filepath: NULL\n") ;
}

void on_peyote_menu_quit_activate()
{
   gtk_main_quit() ;
}



