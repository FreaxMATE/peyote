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

#include "peyote-export-dialog.h"

PeyoteExportDialog *peyote_export_dialog_new()
{
   PeyoteExportDialog *new ;
   new = malloc (sizeof(PeyoteExportDialog)) ;
   return new ;
}

void peyote_export_dialog_initialize()
{
   peyote->export_dialog->left_margin = 40 ;
   peyote->export_dialog->left_margin = 450 ;

   peyote->export_dialog->dialog = GTK_DIALOG(gtk_builder_get_object(peyote->window->builder,
                                                "peyote_export_dialog")) ;
   peyote->export_dialog->cancel = GTK_BUTTON(gtk_builder_get_object(peyote->window->builder,
                                                "peyote_export_dialog_cancel")) ;
   peyote->export_dialog->export = GTK_BUTTON(gtk_builder_get_object(peyote->window->builder,
                                               "peyote_export_dialog_export")) ;

   peyote->export_dialog->left_margin_entry = GTK_SPIN_BUTTON(gtk_builder_get_object(peyote->window->builder,
                                                        "peyote_export_dialog_left_margin")) ;
   peyote->export_dialog->right_margin_entry = GTK_SPIN_BUTTON(gtk_builder_get_object(peyote->window->builder,
                                                        "peyote_export_dialog_right_margin")) ;


   return ;
}

void peyote_export_dialog_run()
{
   gtk_dialog_run(peyote->export_dialog->dialog) ;

   gtk_widget_hide(GTK_WIDGET(peyote->export_dialog->dialog)) ;
   return ;
}

void on_peyote_export_dialog_export_clicked()
{
   peyote->export_dialog->left_margin = gtk_spin_button_get_value(peyote->export_dialog->left_margin_entry) ;
   peyote->export_dialog->right_margin = gtk_spin_button_get_value(peyote->export_dialog->right_margin_entry) ;
   gtk_dialog_response(peyote->export_dialog->dialog, GTK_RESPONSE_APPLY) ;
   return ;
}

void on_peyote_export_dialog_cancel_clicked()
{
   gtk_dialog_response(peyote->export_dialog->dialog, GTK_RESPONSE_CANCEL) ;
   return ;
}

