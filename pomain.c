#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "povacca.h"

static int onestring (struct pv_stack *s, char *str)
{
	struct pv_oper *p;
	int i;
	char *str2;

	/* first: use numbers */
	i = strtol(str, &str2, 0);
	if (!str2 || !*str2) {
		s->v[s->sp++] = i;
		return 0;
	}

	/* not a number: operands */
	for (p = pv_first; p < pv_last; p++)
		if (!strcmp(str, p->name))
			break;
	if (p == pv_last) {
		fprintf(stderr, "%s: not found\n", str);
		return -1;
	}
	return p->f(s, str);
}

int main(int argc, char **argv)
{
	int i;
	static struct pv_stack stack;
	struct pv_stack *s = &stack;

	for (i = 1; i < argc; i++)
		onestring(s, argv[i]);

	for (i = 0; i < s->sp; i++)
		printf("stack[%i]: %i\n", i, s->v[i]);

	return 0;
}
