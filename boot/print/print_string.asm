[bits 16]

print_string:
  pusha

  print_string_loop:
    mov al, [si]
    add si, 1
    cmp al, 0
    je print_string_fin

    mov ah, 0x0e
    mov bx, 15
    int 0x10
    jmp print_string_loop

  print_string_fin:
    popa
    ret
