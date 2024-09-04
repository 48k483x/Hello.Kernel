Section .text
	;; Multiboot
	align 4
	dd 0x1BADB002  ; magic number
	dd 0x00 ; flags
	dd - (0x1BADB002 + 0x00); checksum m+f+c == 0

global _start
extern k_main

_start:
	cli
	call k_main
	hlt
