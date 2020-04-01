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

#ifndef _peyote_h_
#define _peyote_h_

#include <gtk/gtk.h>
#include <glib.h>

#include <cairo.h>
#include <cairo-pdf.h>

typedef struct _PeyoteApplication PeyoteApplication ;
typedef struct _PeyoteRender PeyoteRender ;
typedef struct _PeyoteWindow PeyoteWindow ;
typedef struct _PeyoteTab PeyoteTab ;
typedef struct _PeyoteMenu PeyoteMenu ;
typedef struct _PeyoteDialog PeyoteDialog ;

typedef struct _PeyoteApplication
{
   PeyoteWindow *window ;
   PeyoteRender *render ;
   PeyoteMenu   *menu ;
   PeyoteTab    *tab ;
   PeyoteDialog *dialog ;
   char *filepath ;

} PeyoteApplication ;

typedef struct _PeyoteRender
{
   cairo_surface_t *surface ;
   cairo_t *cr ;

} PeyoteRender ;

typedef struct _PeyoteWindow
{
   GtkBuilder *builder ;
   GtkWindow  *window ;
   GtkAboutDialog *about_dialog ;
   GtkBox *main_box ;

} PeyoteWindow ;

typedef struct _PeyoteTab
{
   GtkTextBuffer *tab_text ;
   char *tabs, *artist, *song, *album ;

} PeyoteTab ;

typedef struct _PeyoteMenu
{
   GtkImageMenuItem *peyote_menu_open ;
   GtkImageMenuItem *peyote_menu_quit ;

} PeyoteMenu ;

typedef struct _PeyoteDialog
{
   GtkDialog *dialog ;
   GtkButton *cancel, *apply ;
   GtkEntry *artist_entry, *song_entry, *album_entry ;
   char *artist, *song, *album ;

} PeyoteDialog ;

#endif /* _peyote_h_ */

