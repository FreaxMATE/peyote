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

#ifndef _peyote_metadata_dialog_h_
#define _peyote_metadata_dialog_h_

#include <gtk/gtk.h>

#include "peyote.h"
#include "peyote-application.h"

typedef struct _PeyoteMetadataDialog
{
   GtkDialog *dialog ;
   GtkButton *cancel, *apply ;
   GtkEntry *artist_entry, *song_entry, *album_entry ;
   char *artist, *song, *album ;

} PeyoteMetadataDialog ;

PeyoteMetadataDialog *peyote_metadata_dialog_new(void) ;
void peyote_metadata_dialog_initialize(void) ;
void peyote_metadata_dialog_run(void) ;

#endif /* _peyote_metadata_dialog_h_ */

