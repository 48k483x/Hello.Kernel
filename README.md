
```javascript
const "Hello world kernel" = {
 "type": "Simple kernel (asm, C)",
 "files": {
   "kernel.c": "Kernel code",
   "multiboot.S": "Bootloader", 
   "link.ld": "Linker script"
 },
 "build": [
   "nasm -f elf32 multiboot.S -o kasm.o",
   "gcc -m32 -c kernel.c -o kc.o", 
   "ld -m elf_i386 -T link.ld -o kernel kasm.o kc.o"
 ],
 "run": "qemu-system-i386 -kernel kernel"
}
