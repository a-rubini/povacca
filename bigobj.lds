SECTIONS
{
	.text : { *(.text) }

	.data : {
		*(.data);
		pv_first = .;
		*(.oper);
		pv_last = .;
		}

	.rodata : { *(.rodata) }

	.bss : { *(.bss) }
}