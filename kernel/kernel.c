#include "drivers/video/video.h"
#include "drivers/irq/irq.h"

void main() {
  initCanvas();
  idt_init();
  while(1);
}
