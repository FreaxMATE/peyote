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

typedef struct _PeyoteApplication PeyoteApplication ;
typedef struct _PeyoteWindow PeyoteWindow ;
typedef struct _PeyoteTab PeyoteTab ;
typedef struct _PeyoteMenu PeyoteMenu ;

typedef struct _PeyoteApplication
{
   PeyoteWindow *window ;
   PeyoteMenu   *menu ;
   PeyoteTab    *tab ;

} PeyoteApplication ;

typedef struct _PeyoteWindow
{
   GtkBuilder *builder ;
   GtkWindow  *window ;
   GtkAboutDialog *about_dialog ;

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


#endif /* _peyote_h_ */

