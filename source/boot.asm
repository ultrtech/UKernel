bits 32 ;; 32-bit
section .text
        align 4
        dd 0x1BADB002            ;magic value
        dd 0x00                  ;flags
        dd - (0x1BADB002 + 0x00) ;checksum. m+f+c should be zero

global start
extern kmain

start:
  cli 			; disable interrupts
  mov esp, stack_space	; set stack pointer
  call kmain
  hlt		 	; disable CPU after kernel exit

section .bss
resb 8192		; 8KB of stack space
stack_space: