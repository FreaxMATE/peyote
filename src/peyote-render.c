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

//   pdf_dir = g_strdup_printf("%s/.cache/peyote/tabs.pdf", g_get_home_dir()) ;
   pdf_dir = g_strdup_printf("%s/tabs.pdf", g_get_home_dir()) ;
   peyote->render->surface = cairo_pdf_surface_create(pdf_dir, 504, 648) ;
   peyote->render->cr = cairo_create(peyote->render->surface) ;

   cairo_set_source_rgb(peyote->render->cr, 0, 0, 0) ;
   cairo_select_font_face (peyote->render->cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL) ;
   cairo_set_font_size (peyote->render->cr, 24.0);
   cairo_move_to(peyote->render->cr, 30.0, 50.0) ;
   cairo_show_text(peyote->render->cr, peyote->tab->song) ;
   cairo_set_font_size (peyote->render->cr, 14.0);
   cairo_move_to(peyote->render->cr, 300.0, 50.0) ;
   cairo_show_text(peyote->render->cr, peyote->tab->artist) ;

   int i, y_tabs = 80 ;
   cairo_set_source_rgba(peyote->render->cr, 0, 0, 0, 1) ;
   cairo_set_line_width(peyote->render->cr, 1) ;
   for (i = 0; i < 6; ++i)
   {
      cairo_move_to(peyote->render->cr, 40, y_tabs) ;
      cairo_line_to(peyote->render->cr, 450, y_tabs) ;
      y_tabs += 5 ;
   }
   cairo_stroke(peyote->render->cr) ;
   cairo_show_page(peyote->render->cr) ;
   cairo_surface_destroy(peyote->render->surface) ;
   cairo_destroy(peyote->render->cr) ;
   g_free(pdf_dir) ;
   return 0 ;
}

