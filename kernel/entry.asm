[bits 32]
[extern main]

global outb
global write_port

call main
jmp $

outb:
  mov   edx, [esp + 4]    
	mov   al, [esp + 4 + 4]  
	out   dx, al  
	ret

write_port:
	mov   edx, [esp + 4]    
	mov   al, [esp + 4 + 4]  
	out   dx, al  
	ret

%include "drivers/irq/irq.asm"
