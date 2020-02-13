#include "irq.h"
#include "../../lib/stdint.h"
#include "../video/video.h"

extern void outb();
extern void write_port();

struct IDT_entry{
	unsigned short int offset_lowerbits;
	unsigned short int selector;
	unsigned char zero;
	unsigned char type_attr;
	unsigned short int offset_higherbits;
} __attribute__((packed));

struct IDT_entry IDT[256];

void idt_init() {
  extern int load_idt();
  extern int irq1();

  unsigned long irq1_address;
  unsigned long idt_address;
  unsigned long idt_ptr[2];

  /* remapping the PIC */
  write_port(0x20 , 0x11);
	write_port(0xA0 , 0x11);

	/* ICW2 - remap offset address of IDT */
	/*
	* In x86 protected mode, we have to remap the PICs beyond 0x20 because
	* Intel have designated the first 32 interrupts as "reserved" for cpu exceptions
	*/
	write_port(0x21 , 0x20);
	write_port(0xA1 , 0x28);

	/* ICW3 - setup cascading */
	write_port(0x21 , 0x00);  
	write_port(0xA1 , 0x00);  

	/* ICW4 - environment info */
	write_port(0x21 , 0x01);
	write_port(0xA1 , 0x01);
	/* Initialization finished */

	/* mask interrupts */
	write_port(0x21 , 0xff);
	write_port(0xA1 , 0xff);


  irq1_address = (unsigned long)irq1; 
  IDT[0x21].offset_lowerbits = irq1_address & 0xffff;
	IDT[0x21].selector = 0x08; /* KERNEL_CODE_SEGMENT_OFFSET */
	IDT[0x21].zero = 0;
	IDT[0x21].type_attr = 0x8e; /* INTERRUPT_GATE */
	IDT[0x21].offset_higherbits = (irq1_address & 0xffff0000) >> 16;


  /* fill the IDT descriptor */
  idt_address = (unsigned long)IDT ;
	idt_ptr[0] = (sizeof (struct IDT_entry) * 256) + ((idt_address & 0xffff) << 16);
	idt_ptr[1] = idt_address >> 16 ;

  load_idt(idt_ptr);
  outb(0x21, 0xfd);
};


void irq1_handler(void) {
  //outb(0x20, 0x20); //EOI
  setBackgroundColor(COL_GREEN);
}

