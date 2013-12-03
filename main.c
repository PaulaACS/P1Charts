#include <stdio.h>
#include "drawing.h"
#include "storage.h"
#include <string.h>
#include <stdio.h>


int main() {
	Chart * chart = ChartCreate("test.json");
	Drawer * cairo = DrawerInit(800, 600, chart->fileType, chart->filePath);
	Rectangle base = {0, //x
					  0, //y
					  800, //width
					  600, //height
					  0.0, // borderWidth
					  {1.0, 1.0, 1.0, 1.0},// Color Bg
					  {0.0, 0.0, 0.0, 0.0}// Color border (borderless)
	};
	DrawerDrawRectangle(cairo, base);

	Rectangle rect = {400-50, //x
					  300-50, //y
					  100, //width
					  100, //height
					  10.0, // borderWidth
					  {1.0, 0.0, 1.0, 1.0}, // Color Bg
					  {0.0, 1.0, 0.0, 1.0} // Color border
	};
	Arc arc = {400, 
			300,
			10,
			0,
			4*M_PI,
			10.0,
			{1.0, 0.0, 0.0, 1.0},
			{1.0, 1.0, 1.0, 1.0}
	};
	DrawerDrawRectangle(cairo, rect);
	DrawerDrawArc(cairo, arc);
	DrawerSave(cairo, chart->fileType, chart->filePath);
	DrawerDestroy(cairo);
	return 0;
}
