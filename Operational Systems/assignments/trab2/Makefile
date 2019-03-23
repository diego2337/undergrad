all:
	gcc -ffreestanding -c kernel.c -o kernel.o
	ld -o kernel.bin -Ttext 0x1000 kernel.o --oformat binary
	nasm bootk.asm -f bin -o boot_sect.bin
	cat boot_sect.bin kernel.bin > os-image
