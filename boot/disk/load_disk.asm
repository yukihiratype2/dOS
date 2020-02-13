[bits 16]

disk_load:
  push dx

  mov ah, 0x02
  mov al, dh
  mov ch, 0x00
  mov dh, 0x00
  mov cl, 0x02

  int 0x13

  jc disk_error

  pop dx
  cmp dh, al
  jne disk_error
  mov si, DISK_SUCCESS_MSG
  call print_string
  ret


disk_error:
  mov si, DISK_ERROR_MSG
  call print_string
  jmp $

DISK_SUCCESS_MSG db "Disk R CMP", 13, 0
DISK_ERROR_MSG db "Disk read error", 0
