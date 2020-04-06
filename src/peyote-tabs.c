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

#include "peyote-tabs.h"

PeyoteTabs *peyote_tabs_new()
{
   PeyoteTabs *new ;
   new = malloc(sizeof(PeyoteTabs)) ;
   return new ;
}

int peyote_tabs_initialize()
{
   return 0 ;
}

void peyote_tabs_load_tabs()
{
   if (peyote->files->current->parser->tabs == NULL)
   {
      fprintf (stderr, "Peyote ERROR: parser->tabs not initialized\n") ;
      return ;
   }
   int k, j, i ;

   peyote->tabs->nlines = 6 ;
   peyote->tabs->nlinelen = 0 ;
   while (peyote->files->current->parser->tabs[peyote->tabs->nlinelen] != '\n')
      ++peyote->tabs->nlinelen ;
   ++peyote->tabs->nlinelen ;

   /*  parse tabs to two-dimensional matrix */
   peyote->tabs->tabs = calloc (peyote->tabs->nlines, sizeof(char *)) ;
   for (i = 0; i < peyote->tabs->nlines; ++i)
      peyote->tabs->tabs[i] = calloc (peyote->tabs->nlinelen, sizeof(char)) ;
   k = 0 ;
   for (j = 0; j < peyote->tabs->nlines; ++j)
   {
      for (i = 0; i < peyote->tabs->nlinelen; ++i)
      {
         if (peyote->files->current->parser->tabs[k] == '\n')
         {
            peyote->tabs->tabs[j][i] = 0 ;
            k++ ;
            break ;
         }
         if (peyote->files->current->parser->tabs[k] == '-')
            peyote->tabs->tabs[j][i] = ' ' ;
         else
            peyote->tabs->tabs[j][i] = peyote->files->current->parser->tabs[k] ;
         k++ ;
      }
   }
   peyote->tabs->tuning = calloc (peyote->tabs->nlines, sizeof(int)) ;
   for (j = 0; j < peyote->tabs->nlines; ++j)
   {
      peyote->tabs->tuning[j] = peyote->tabs->tabs[j][0] ;
   }
   return ;
}

