#include "video.h"

char canvas[320][200];

void setBackgroundColor(base_color color) {
  for (int x = 0; x < 320; x++) {
    for (int y = 0; y < 200; y++) {
      canvas[x][y] = color;
    }
  }
  setCanvas();
}

void drawRect(int pos_x, int pos_y, int width, int height, base_color fill_color) {
  for (int x = pos_x; x < (pos_x + width); x++) {
    for (int y = pos_y; y < (pos_y + height); y++) {
      canvas[x][y] = fill_color;
    }
  }
  setCanvas();
}

void setCanvas() {
  char *video_mm = (char*) 0xa0000;
  for (int y = 0; y < 200; y++) {
    for (int x = 0; x < 320; x++) {
      *video_mm = canvas[x][y];
      *video_mm++;
    }
  }
}

void initCanvas() {
  setBackgroundColor(COL_WHITE);
  setCanvas();
}

