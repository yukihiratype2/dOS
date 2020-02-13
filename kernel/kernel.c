#include "drivers/video/video.h"
#include "drivers/irq/irq.h"
#include "drivers/keyboard/keyboard.h"

#include "graphic/graphic.h"

void main() {
  char (*canvas)[200];
  canvas = initCanvas();
  idt_init();
  init_keyboard();
  put_char(canvas, 'A', COL_GREEN, 0, 2);
  put_char(canvas, 'B', COL_BLACK, 12, 2);
  put_char(canvas, 'C', 13, 24, 2);
  put_char(canvas, '1', 9, 24 + 12, 2);
}
