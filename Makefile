bl: boot/boot.asm
	cd boot && nasm -f bin boot.asm -o boot.bin
os: bl
	cd kernel && nasm -f elf entry.asm -o entry.o
	cd kernel/drivers/video && x86_64-elf-gcc -m32 -ffreestanding -c video.c -o video.o
	cd kernel/drivers/irq && x86_64-elf-gcc -m32 -ffreestanding -c irq.c -o irq.o
	cd kernel && x86_64-elf-gcc -m32 -ffreestanding -c kernel.c -o kernel.o
	cd kernel && x86_64-elf-ld -melf_i386  -o kernel.bin -Ttext 0x9000 entry.o kernel.o drivers/video/video.o drivers/irq/irq.o  --oformat binary
	cd kernel && cat kernel.bin zeros > k.bin

assemb: os
	cat boot/boot.bin kernel/k.bin > os_img

bochs: assemb
	bochs -q

run: assemb
	qemu-system-x86_64 os_img

clean:
	rm *.bin
