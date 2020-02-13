#include "graphic.h"
#include "../drivers/video/video.h"

int char_a[8] = {0x18, 0x24, 0x42, 0xc3, 0xff, 0x81, 0x81, 0x81};
int char_b[8] = {0xf8, 0x84, 0x88, 0xfc, 0x82, 0x81, 0x81, 0xfe};
int char_c[8] = {0x3e, 0x41, 0x80, 0x80, 0x80, 0x80, 0x41, 0x3e};

int char_1[8] = {0x18, 0x28, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3e};

int *(char_list[128]);

void put_char(char (*canvas)[200], char c, base_color color, int pos_x, int pos_y) {
  char_list[(int)'A'] = char_a;
  char_list[(int)'B'] = char_b;
  char_list[(int)'C'] = char_c;
  char_list[(int)'1'] = char_1;
  for (int y = pos_y; y < pos_y + 8; y++) {
    for (int x = pos_x; x < pos_x + 8; x++) {
      canvas[x][y] = char_list[(int)c][y - pos_y] & ( 1 << (7 - (x - pos_x))) ? color : canvas[x][y];
    }
  }
  setCanvas();
};
