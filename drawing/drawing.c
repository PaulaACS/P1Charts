#include "drawing.h"

CairoDef * CairoDef_Init(int width, int height) {
	CairoDef * self = malloc(sizeof(CairoDef));
	self->surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
    self->context = cairo_create(self->surface);
    cairo_set_antialias(self->context, CAIRO_ANTIALIAS_BEST);
    return self;
}

void CairoDef_Destroy(CairoDef * self){
	cairo_destroy(self->context);
    cairo_surface_destroy(self->surface);
    free(self);
}

void CairoDefDrawRectangle(CairoDef * self, Rectangle rect) {
	cairo_save(self->context);
	cairo_set_line_width(self->context, rect.borderWidth);
	cairo_rectangle (self->context, rect.x, rect.y, rect.width, rect.height);
	cairo_set_source_rgba(self->context,
						  rect.bg.r,
						  rect.bg.g,
						  rect.bg.b,
						  rect.bg.a);
	cairo_fill_preserve(self->context);
 	cairo_set_source_rgba(self->context,
 						  rect.border.r,
 						  rect.border.g,
 						  rect.border.b,
 						  rect.border.a);
 	cairo_stroke(self->context);
 	cairo_restore(self->context);
}
