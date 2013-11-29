#include <cairo/cairo.h>
#include <stdlib.h>

struct _cairo_definition {
	cairo_surface_t *surface;
    cairo_t * context;
};

typedef struct _cairo_definition CairoDef;

struct _color {
	float r, g, b, a;
};

typedef struct _color Color;

struct _rectangle {
	int x;
	int y;
	float width;
	float height;
	float borderWidth;
	Color bg;  // fundo
	Color border;
};

typedef struct _rectangle Rectangle;

struct _arc {
	int x;
	int y;
	int r;
	float borderwidth;
	float angle_i; 
	float angle_f;
	Color bg;
	Color border;
};

typedef  struct _arc Arc;

CairoDef * CairoDef_Init();
void CairoDef_Destroy(CairoDef * self);
void CairoDefDrawRectangle(CairoDef * self, Rectangle rect);
void CairoDefDrawArc(CairoDef * self, Arc arc);


