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

#include "peyote-filechooser.h"

char *peyote_filechooser_open_file()
{
   GtkWidget *dialog ;
   gint res ;

   dialog = gtk_file_chooser_dialog_new ("Open File",
                                         peyote->peyote_window->window,
                                         GTK_FILE_CHOOSER_ACTION_OPEN,
                                         "Cancel",
                                         GTK_RESPONSE_CANCEL,
                                         "Open",
                                         GTK_RESPONSE_ACCEPT,
                                         NULL) ;

   res = gtk_dialog_run (GTK_DIALOG (dialog)) ;
   if (res == GTK_RESPONSE_ACCEPT)
   {
      char *filename ;
      GtkFileChooser *chooser = GTK_FILE_CHOOSER (dialog) ;
      filename = gtk_file_chooser_get_filename (chooser) ;
      gtk_widget_destroy (dialog) ;
      return filename ;
   }
   gtk_widget_destroy (dialog);
   return NULL ;
}
