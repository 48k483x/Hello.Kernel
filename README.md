
```javascript
const SimpleKernel{
  "projectName": "MyOs",
  "description": "A simple operating system project showcasing basic OS development concepts",
  "type": "Simple kernel in asm, C",
  "fileStructure": {
    "src": {
      "kernel.c": "Kernel code",
      "multiboot.S": "Multiboot bootloader",
      "link.ld": "Linker script"
    }
  },
  "buildSteps": [
    {
      "step": "Create object file from multiboot.S",
      "command": "nasm -f elf32 multiboot.S -o kasm.o",
      "output": "kasm.o",
      "format": "ELF-32 bit"
    },
    {
      "step": "Compile kernel.c",
      "command": "gcc -m32 -c kernel.c -o kc.o",
      "output": "kc.o"
    },
    {
      "step": "Link object files",
      "command": "ld -m elf_i386 -T link.ld -o kernel kasm.o kc.o",
      "output": "kernel"
    }
  ],
  "run": {
    "emulator": "qemu",
    "command": "qemu-system-i386 -kernel kernel"
  }
}
