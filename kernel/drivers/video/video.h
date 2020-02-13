#define COL_WHITE 15
#define COL_BLACK 0
#define COL_GREEN 10

typedef unsigned int base_color;

void setBackgroundColor(base_color color);

void drawRect(int x, int y, int width, int height, base_color fillColor);

void setCanvas();

char  (*initCanvas())[200];
