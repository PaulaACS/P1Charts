#include <jansson.h>

struct _datum {
	double percentage;
	const char * label;
};
typedef struct _datum Datum;

struct _chart {
	const char * fileName;
	const char * fileType;
	int width;
	int height;
	Datum ** content;
};
typedef struct _chart ChartDetails;

ChartDetails * ChartDetailsCreate(char * filePath);
