

struct pv_stack {
	int sp;
	int v[32];
};

struct pv_oper {
    char name[8];
    int (*f)(struct pv_stack *s, char *str);
};

extern struct pv_oper pv_first[], pv_last[];

#define pv_operand(sname, name, f)        \
    struct pv_oper                        \
    __attribute__((__section__(".oper"))) \
    __oper_##sname = {name, f}

