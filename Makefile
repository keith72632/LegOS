
CC = arm-none-eabi-gcc

all: run

boot.o: boot.S
	${CC} -mcpu=cortex-a7 -fpic -ffreestanding -c $^ -o $@

kernel.o: kernel.c
	${CC} -mcpu=cortex-a7 -fpic -ffreestanding -std=gnu99 -c $^ -o $@ -O2 -Wall -Wextra

myos.elf: boot.o kernel.o
	${CC} -T linker.ld -o $@ -ffreestanding -O2 -nostdlib $^ 

kernel8.img: myos.elf
	arm-none-eabi-objcopy $^ -O binary $@

run: myos.elf
	qemu-system-arm -m 1024 -M raspi2 -serial stdio -kernel myos.elf

clean:
	rm *.o *.elf *.img