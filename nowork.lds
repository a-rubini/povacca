OUTPUT_FORMAT("elf32-i386", "elf32-i386", "elf32-i386")
OUTPUT_ARCH(i386)
ENTRY(_start)

SECTIONS
{
  . = 0x12345000;
  .text : { *(.text) }

  pv_first = .;
  .oper : { *(.oper) }
  pv_last = .;

  .rodata : { *(.rodata) }
  .data : { *(.data) }

  __bss_start = .;
  .bss : { *(.bss) }
  __bss_end = .;

   _end = .;
}