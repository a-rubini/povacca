SECTIONS
{
	.data : {
		pv_first = .;
		*(.oper);
		pv_last = .;
		}
}
