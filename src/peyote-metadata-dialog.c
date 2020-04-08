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

#include "peyote-metadata-dialog.h"

PeyoteMetadataDialog *peyote_metadata_dialog_new()
{
   PeyoteMetadataDialog *new ;
   new = malloc (sizeof(PeyoteMetadataDialog)) ;
   return new ;
}

void peyote_metadata_dialog_initialize()
{
   peyote->metadata_dialog->dialog = GTK_DIALOG(gtk_builder_get_object(peyote->window->builder,
                                                "peyote_metadata_dialog")) ;
   peyote->metadata_dialog->cancel = GTK_BUTTON(gtk_builder_get_object(peyote->window->builder,
                                                "peyote_metadata_dialog_cancel")) ;
   peyote->metadata_dialog->apply = GTK_BUTTON(gtk_builder_get_object(peyote->window->builder,
                                               "peyote_metadata_dialog_apply")) ;

   peyote->metadata_dialog->artist_entry = GTK_ENTRY(gtk_builder_get_object(peyote->window->builder,
                                                     "peyote_metadata_dialog_artist")) ;
   peyote->metadata_dialog->song_entry = GTK_ENTRY(gtk_builder_get_object(peyote->window->builder,
                                                   "peyote_metadata_dialog_song")) ;
   peyote->metadata_dialog->album_entry = GTK_ENTRY(gtk_builder_get_object(peyote->window->builder,
                                                    "peyote_metadata_dialog_album")) ;
   return ;
}

void peyote_metadata_dialog_run()
{
   gtk_dialog_run(peyote->metadata_dialog->dialog) ;
   peyote->files->current->parser->artist = peyote->metadata_dialog->artist ;
   peyote->files->current->parser->song = peyote->metadata_dialog->song ;
   peyote->files->current->parser->album = peyote->metadata_dialog->album ;
   gtk_widget_hide(GTK_WIDGET(peyote->metadata_dialog->dialog)) ;
   return ;
}

void on_peyote_metadata_dialog_apply_clicked()
{
   if (strcmp(gtk_entry_get_text(peyote->metadata_dialog->artist_entry), ""))
      peyote->metadata_dialog->artist = g_strdup(gtk_entry_get_text(peyote->metadata_dialog->artist_entry)) ;
   else
      peyote->metadata_dialog->artist = g_strdup("Unknown") ;

   if (strcmp(gtk_entry_get_text(peyote->metadata_dialog->song_entry), ""))
      peyote->metadata_dialog->song = g_strdup(gtk_entry_get_text(peyote->metadata_dialog->song_entry)) ;
   else
      peyote->metadata_dialog->song = g_strdup("Unknown") ;

   if (strcmp(gtk_entry_get_text(peyote->metadata_dialog->album_entry), ""))
      peyote->metadata_dialog->album = g_strdup(gtk_entry_get_text(peyote->metadata_dialog->album_entry)) ;
   else
      peyote->metadata_dialog->album = g_strdup("Unknown") ;

   gtk_dialog_response(peyote->metadata_dialog->dialog, GTK_RESPONSE_APPLY) ;
   return ;
}

void on_peyote_metadata_dialog_cancel_clicked()
{
   peyote->metadata_dialog->artist = g_strdup("Unknown") ;
   peyote->metadata_dialog->song = g_strdup("Unknown") ;
   peyote->metadata_dialog->album = g_strdup("Unknown") ;
   gtk_dialog_response(peyote->metadata_dialog->dialog, GTK_RESPONSE_CANCEL) ;
   return ;
}

