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

#ifndef _peyote_file_h_
#define _peyote_file_h_

#include <gtk/gtk.h>

#include "peyote.h"
#include "peyote-application.h"

typedef struct _PeyoteFile
{
   GtkLabel *tab_label ;
   GtkScrolledWindow *scroll ;
   GtkTextView   *text_view ;
   GtkTextBuffer *text_buffer ;

   PeyoteFileParser *parser ;
   char *path ;

} PeyoteFile ;

PeyoteFile *peyote_file_new(void) ;
void peyote_file_initialize(PeyoteFile *file, char *filepath) ;

#endif /* _peyote_file_h_ */

