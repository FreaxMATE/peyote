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

#ifndef _peyote_window_h_
#define _peyote_window_h_

#include <gtk/gtk.h>

#include "peyote.h"

extern PeyoteApplication *peyote ;

PeyoteWindow *peyote_window_new(void) ;
int peyote_window_initialize(void) ;
void on_peyote_window_destroy(void) ;

#endif /* _peyote_window_h_ */

