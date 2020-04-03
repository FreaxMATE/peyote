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

#include "peyote-application.h"

PeyoteApplication *peyote_application_new()
{
   PeyoteApplication *new ;
   new = malloc (sizeof(PeyoteApplication)) ;
   return new ;
}

int peyote_application_initialize(int argc, char **argv)
{
   gtk_init (&argc, &argv) ;

   peyote->window = peyote_window_new() ;
   peyote_window_initialize() ;
   peyote->render = peyote_render_new() ;
   peyote_render_initialize() ;
   peyote->menu = peyote_menu_new() ;
   peyote_menu_initialize() ;
   peyote->dialog = peyote_dialog_new() ;
   peyote_dialog_initialize() ;
   peyote->tabs = peyote_tabs_new() ;
   peyote_tabs_initialize() ;
   peyote->filepath = NULL ;
   peyote->parser = peyote_file_parser_new() ;
   if (argc > 2)
      return 1 ;
   argc == 2 ?  peyote_file_parser_initialize(argv[1]) : peyote_file_parser_initialize("NOFILE") ;
   return 0 ;
}

int peyote_application_run(int argc, char **argv)
{
   gtk_main() ;
   return 0 ;
}

gboolean peyote_application_is_new_document()
{
   return peyote->filepath == NULL ? TRUE : FALSE ;
}

