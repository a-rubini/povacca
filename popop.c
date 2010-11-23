#include <stdio.h>
#include "povacca.h"

int pv_pop(struct pv_stack *s, char *str)
{
	s->sp--;
	return 0;
}

int pv_dup(struct pv_stack *s, char *str)
{
	s->v[s->sp] = s->v[s->sp-1];
	s->sp++;
	return 0;
}

pv_operand(pop, "pop", pv_pop);
pv_operand(dup, "dup", pv_dup);
