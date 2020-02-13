[bits 16]

switch_to_pm:
  mov ax, 0
    mov ss, ax
    mov sp, 0xFFFC

    mov ax, 0
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
  cli
  xor ax, ax
  mov ds, ax
  lgdt  [gdt_descriptor]

  mov  eax, cr0
  or  eax, 0x1
  mov  cr0, eax

  jmp CODE_SEG:init_pm


[bits 32]

init_pm:
  mov ax, DATA_SEG
  mov ds, ax
  mov es, ax
  mov fs, ax
  mov gs, ax
  mov ss, ax

  mov ebp, 0x90000
  mov esp, ebp

