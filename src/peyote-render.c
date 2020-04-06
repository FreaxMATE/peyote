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

#include "peyote-render.h"

PeyoteRender *peyote_render_new()
{
   PeyoteRender *new ;
   new = malloc (sizeof(PeyoteRender)) ;
   return new ;
}

int peyote_render_initialize()
{
   return 0 ;
}

int peyote_render_make_pdf()
{
   char *pdf_dir ;

   /* load tabs into a matrix */
   peyote_tabs_load_tabs() ;
   /* create cairo surface from pdf */
   pdf_dir = g_strdup_printf("%s/tabs.pdf", g_get_home_dir()) ;
//   peyote->render->surface = cairo_pdf_surface_create(pdf_dir, 1000.0, 1000.0) ;
   peyote->render->surface = cairo_pdf_surface_create(pdf_dir, 595.4, 842) ;
   if (cairo_surface_status(peyote->render->surface) != CAIRO_STATUS_SUCCESS)
      fprintf (stderr, "Peyote WARNING: cairo_pdf_surface_create did not run successful\n") ;
   peyote->render->cr = cairo_create(peyote->render->surface) ;

   /* draw title with the song name and the artist's name */
   cairo_set_source_rgb(peyote->render->cr, 0, 0, 0) ;
   cairo_select_font_face(peyote->render->cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL) ;
   cairo_set_font_size (peyote->render->cr, 20.0);
   cairo_move_to(peyote->render->cr, 150.0, 50.0) ;
   cairo_show_text(peyote->render->cr, peyote->files->current->parser->song) ;
   cairo_set_source_rgb(peyote->render->cr, 0.5, 0.5, 0.5) ;
   cairo_set_font_size (peyote->render->cr, 12.0);
   cairo_move_to(peyote->render->cr, 350.0, 50.0) ;
   cairo_show_text(peyote->render->cr, peyote->files->current->parser->artist) ;

   /* draw music lines without tabs */
   int n_paragraphs = 8 ;
   int d_line = 5 ;        // distance between the six music lines
   int d_paragraph = 30 ;  // distance between the music paragraphs
   double upper_end = 80.0 ;
   int right_end = 450 ;
   int left_end = 40 ;
   int d_notes = 5 ;      // x distance between the picking points
   int j, i ;
   double y_tabs = upper_end ;
   cairo_set_source_rgba(peyote->render->cr, 0, 0, 0, 1) ;
   cairo_set_line_width(peyote->render->cr, 0.5) ;
   for (j = 0; j < n_paragraphs; ++j)
   {
      for (i = 0; i < peyote->tabs->nlines; ++i)
      {
         cairo_move_to(peyote->render->cr, 50, y_tabs) ;
         cairo_line_to(peyote->render->cr, 450, y_tabs) ;
         y_tabs += d_line ;
      }
      y_tabs += d_paragraph ;
   }

   /* add tabs to music lines */
   cairo_set_font_size (peyote->render->cr, 6.0);
   char str[2] = "\0" ;
   y_tabs = upper_end + 1.75 ;
   gboolean next_paragraph = FALSE ;
   int paragraph = 0 ;
   int line = 0 ;
   int x_vec = 0 ;
   int x_pos = left_end ;

   while (paragraph < n_paragraphs) // number of paragraph lines
   {
//      printf ("paragraph: %d\n", paragraph) ;
      while (line < peyote->tabs->nlines) // six lines representing the strings
      {
//         printf ("line: %d\n", line) ;
         if (!next_paragraph)
         {
            x_vec = 0 ;
            x_pos = left_end ;
         }
         else
         {
            x_pos = left_end + 10 ;
            next_paragraph = FALSE ;
         }
         while (x_vec < peyote->tabs->nlinelen) // x direction from left to right
         {
//            printf ("x: %d, xpos: %d, y_tabs: %.0f\n", x_vec, x_pos, y_tabs) ;
            if (x_pos >= right_end) // current x position exceeds right end
            {
               next_paragraph = TRUE ;
               break ;
            }
            cairo_move_to(peyote->render->cr, x_pos, y_tabs) ;
            str[0] = peyote->tabs->tabs[line][x_vec] ;
            cairo_show_text(peyote->render->cr, str) ;
            x_pos += d_notes ;
            x_vec++ ;
         }
         if (paragraph > 0 && x_vec == peyote->tabs->nlinelen)
         {
            ++line ;
            y_tabs = upper_end+1.75 + line*d_line ;
            continue ;
         }
         if (next_paragraph)
            break ;
         y_tabs += d_line ;
         ++line ;
      }
      if (line == peyote->tabs->nlines)
         break ;
      if (!next_paragraph)
      {
         line = 0 ;
         y_tabs += d_paragraph ;
      }
      else
         y_tabs += d_paragraph + d_line*peyote->tabs->nlines ;
      ++paragraph ;
   }

   cairo_stroke(peyote->render->cr) ;
   cairo_show_page(peyote->render->cr) ;
   cairo_surface_destroy(peyote->render->surface) ;
   cairo_destroy(peyote->render->cr) ;
   g_free(pdf_dir) ;
   return 0 ;
}

