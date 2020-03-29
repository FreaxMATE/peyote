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
                                         peyote->window->window,
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

void peyote_filechooser_save_file()
{
   GtkWidget *dialog ;
   GtkFileChooser *chooser ;
   gint res ;

   dialog = gtk_file_chooser_dialog_new ("Save File",
                                         peyote->window->window,
                                         GTK_FILE_CHOOSER_ACTION_SAVE,
                                         "Cancel",
                                         GTK_RESPONSE_CANCEL,
                                         "Save",
                                         GTK_RESPONSE_ACCEPT,
                                         NULL) ;
   chooser = GTK_FILE_CHOOSER(dialog) ;
   gtk_file_chooser_set_do_overwrite_confirmation(chooser, TRUE) ;

   if (peyote_application_is_new_document())
      gtk_file_chooser_set_current_name(chooser, "Untitled document");
   else
      gtk_file_chooser_set_filename(chooser, peyote->filepath) ;

   res = gtk_dialog_run(GTK_DIALOG(dialog)) ;
   if (res == GTK_RESPONSE_ACCEPT)
   {
      char *filename ;
      filename = gtk_file_chooser_get_filename(chooser) ;
      peyote_tab_save_file(filename) ;
      g_free (filename) ;
   }
   gtk_widget_destroy(dialog) ;
   return ;
}

