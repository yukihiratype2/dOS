#include "keyboard.h"
#include "../../lib/helper.h"
#include "../video/video.h"

void init_keyboard() {
  write_port(0x21, 0xfd);
}

void kbd_int_handler() {
  //setBackgroundColor(COL_GREEN);
}
