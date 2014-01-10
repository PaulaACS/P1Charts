#include <stdio.h>
#include "drawing.h"
#include "storage.h"
#include <string.h>

void pizza(Drawer * drawer, Chart * chart) {
    float angle_i = 0.0;
	int i;
    for(i = 0; chart->content[i] != 0; i++) {
        Arc arc = {300, //x
                  300, //y
                  angle_i, //angle_i
                  angle_i + chart->content[i]->percentage*2*M_PI, //angle_f
                  160,   //r
                  1.0, // borderWidth
                  {i*1.0, 1.0, i*0.1, 1.0}, // Color Bg (vermelho, verde, azul, ...)
                  {i*0.3, 0, i*0.3, 1.0} // Color border
        	   };
        DrawerDrawArc(drawer, arc);
        angle_i += chart->content[i]->percentage*2*M_PI;
	}
}
// Obs.: São dois retângulos. 
int main() {
	Chart * chart = ChartCreate("test.json");
	Drawer * cairo = DrawerInit(800, 600, chart->fileType, chart->filePath);
	// Esse aqui é o retângulo "mais externo", como se fosse o papel
	Rectangle base = {0, //x
					  0, //y
					  800, //width
					  650, //height
					  0.0, // borderWidth
					  {1.0, 1.0, 1.0, 1.0},// Color Bg (branco)
					  {0.0, 0.0, 0.0, 0.0}// Color border (borderless)
	};
	DrawerDrawRectangle(cairo, base);
	// Esse aqui é o retângulo "mais interno". 
	Rectangle rect = {0, //x
					  0, //y
					  800, //width
					  650, //height
					  3.0, // borderWidth
					  {1.0, 1.0, 1.0, 1.0}, // Color Bg
					  {0.0, 0.0, 0.0, 1.0} // Color border
	};
	DrawerDrawRectangle(cairo, rect);
	pizza(cairo, chart);
	DrawerSave(cairo, chart->fileType, chart->filePath);
	DrawerDestroy(cairo);
	return 0;
}
