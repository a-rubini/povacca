#include <stdio.h>
#include "povacca.h"

int pv_mul(struct pv_stack *s, char *str)
{
	int sp = s->sp;
	if (sp < 2) {
		fprintf(stderr, "%s: underflow\n", str);
		return -1;
	}
	s->v[sp-2] = s->v[sp-1] * s->v[sp-2];
	s->sp--;
	return 0;
}

pv_operand(mul1, "mul", pv_mul);
pv_operand(mul2, "*",   pv_mul);
