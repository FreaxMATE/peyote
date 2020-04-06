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

#include "peyote-dialog.h"

PeyoteDialog *peyote_dialog_new()
{
   PeyoteDialog *new ;
   new = malloc (sizeof(PeyoteDialog)) ;
   return new ;
}

void peyote_dialog_initialize()
{
   peyote->dialog->dialog = GTK_DIALOG(gtk_builder_get_object(peyote->window->builder, "peyote_dialog")) ;
   peyote->dialog->cancel = GTK_BUTTON(gtk_builder_get_object(peyote->window->builder, "peyote_dialog_cancel")) ;
   peyote->dialog->apply = GTK_BUTTON(gtk_builder_get_object(peyote->window->builder, "peyote_dialog_apply")) ;

   peyote->dialog->artist_entry = GTK_ENTRY(gtk_builder_get_object(peyote->window->builder, "peyote_dialog_artist")) ;
   peyote->dialog->song_entry = GTK_ENTRY(gtk_builder_get_object(peyote->window->builder, "peyote_dialog_song")) ;
   peyote->dialog->album_entry = GTK_ENTRY(gtk_builder_get_object(peyote->window->builder, "peyote_dialog_album")) ;
   return ;
}

void peyote_dialog_run()
{
   gtk_dialog_run(peyote->dialog->dialog) ;
   peyote->files->current->parser->artist = peyote->dialog->artist ;
   peyote->files->current->parser->song = peyote->dialog->song ;
   peyote->files->current->parser->album = peyote->dialog->album ;
   gtk_widget_destroy(GTK_WIDGET(peyote->dialog->dialog)) ;
   return ;
}

void on_peyote_dialog_apply_clicked()
{
   if (strcmp(gtk_entry_get_text(peyote->dialog->artist_entry), ""))
      peyote->dialog->artist = g_strdup(gtk_entry_get_text(peyote->dialog->artist_entry)) ;
   else
      peyote->dialog->artist = g_strdup("Unknown") ;

   if (strcmp(gtk_entry_get_text(peyote->dialog->song_entry), ""))
      peyote->dialog->song = g_strdup(gtk_entry_get_text(peyote->dialog->song_entry)) ;
   else
      peyote->dialog->song = g_strdup("Unknown") ;

   if (strcmp(gtk_entry_get_text(peyote->dialog->album_entry), ""))
      peyote->dialog->album = g_strdup(gtk_entry_get_text(peyote->dialog->album_entry)) ;
   else
      peyote->dialog->album = g_strdup("Unknown") ;

   gtk_dialog_response(peyote->dialog->dialog, GTK_RESPONSE_APPLY) ;
   return ;
}

void on_peyote_dialog_cancel_clicked()
{
   peyote->dialog->artist = g_strdup("Unknown") ;
   peyote->dialog->song = g_strdup("Unknown") ;
   peyote->dialog->album = g_strdup("Unknown") ;
   gtk_dialog_response(peyote->dialog->dialog, GTK_RESPONSE_CANCEL) ;
   return ;
}

