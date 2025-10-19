CC=gcc
CFLAGS=-m32 -ffreestanding -O2 -Wall
ASM=nasm
ASMFLAGS=-f elf

OBJ=arch/boot.o kernel/main.o kernel/process.o kernel/vfs.o kernel/security.o \
    drivers/vga.o drivers/keyboard.o drivers/timer.o

all: kernel.bin

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.S
	$(ASM) $(ASMFLAGS) $< -o $@

kernel.bin: $(OBJ)
	ld -m elf_i386 -Ttext 0x1000 -o kernel.bin $(OBJ)

clean:
	rm -f $(OBJ) kernel.bin
