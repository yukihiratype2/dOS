[bits 32]
[extern main]

global write_port
global read_port

call main
jmp $

write_port:
	mov   edx, [esp + 4]    
	mov   al, [esp + 4 + 4]  
	out   dx, al  
	ret

read_port:
	mov edx, [esp + 4]
	in al, dx	
	ret

%include "drivers/irq/irq.asm"
