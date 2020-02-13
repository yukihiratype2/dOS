[bits 16]
[org 0x7c00]

KERNEL_OFFSET equ 0x9000

mov bp, 0x8000
mov sp, bp

mov si, GT_PROT
call print_string

mov bx, KERNEL_OFFSET
mov dh, 15
call disk_load

  mov al, 0x13
  mov ah, 0x0
  int 0x10

call switch_to_pm

call BEGIN_PM

jmp $

%include "gdt/gdt.asm"
%include "disk/load_disk.asm"
%include "print/pm_print_string.asm"
%include "print/print_string.asm"
%include "switch_to_pm.asm"

[bits 32]

BEGIN_PM:


  ;mov ebx, MSG_PROT_MODE 
  ;call print_string_pm

  call KERNEL_OFFSET

  jmp $

GT_PROT db "Go To PROT", 13,0
MSG_PROT_MODE db "PROT Mode now", 0

times 510-($-$$) db 0

dw 0xaa55
