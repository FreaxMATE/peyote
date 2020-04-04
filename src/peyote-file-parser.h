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

#ifndef _peyote_file_parser_h_
#define _peyote_file_parser_h_

#include <gtk/gtk.h>

#include "peyote.h"
#include "peyote-application.h"
#include "peyote-dialog.h"

PeyoteFileParser *peyote_file_parser_new(void) ;
int peyote_file_parser_initialize(PeyoteFile *file, PeyoteFileParser *parser, GtkTextBuffer *text_buffer, char *filepath) ;
int peyote_file_parser_read_file(PeyoteFileParser *parser) ;
void peyote_file_parser_save_file(char *filepath) ;

#endif /* _peyote_file_parser_h_ */

