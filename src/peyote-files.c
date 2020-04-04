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

#include "peyote-files.h"

PeyoteFiles *peyote_files_new()
{
   PeyoteFiles *new ;
   new = malloc(sizeof(PeyoteFiles)) ;
   return new ;
}

void peyote_files_initialize()
{
   peyote->files->n = 0 ;
   peyote->files->current = NULL ;
   return ;
}

void peyote_files_add_file(char *filepath)
{
   PeyoteFile *new_file ;
   ++peyote->files->n ;
   new_file = peyote_file_new() ;
   peyote_file_initialize(new_file, filepath) ;
   peyote->files->current = new_file ;
   peyote->files->list = g_list_append(peyote->files->list, new_file) ;
   return ;
}

void peyote_files_remove_file()
{
   --peyote->files->n ;
   return ;
}




