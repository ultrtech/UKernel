ukernel : kernel.o screen.o boot.o
	ld -m elf_i386 -T source/link.ld -o build/ukernel.out out/boot.o out/screen.o out/kernel.o
kernel.o : source/kernel.c
	gcc -m32 -c source/kernel.c -o out/kernel.o
screen.o : source/screen.c
	gcc -m32 -c source/screen.c -o out/screen.o
boot.o : source/boot.asm
	nasm -f elf32 source/boot.asm -o out/boot.o
clean :
	rm out/*.o && rm build/*.out
test :
	qemu-system-i386 -kernel build/ukernel.out -curses
