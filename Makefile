CFLAGS = -Wall -ggdb

AS              = $(CROSS_COMPILE)as
LD              = $(CROSS_COMPILE)ld
CC              = $(CROSS_COMPILE)gcc
CPP             = $(CC) -E
AR              = $(CROSS_COMPILE)ar
NM              = $(CROSS_COMPILE)nm
STRIP           = $(CROSS_COMPILE)strip
OBJCOPY         = $(CROSS_COMPILE)objcopy
OBJDUMP         = $(CROSS_COMPILE)objdump


povacca: povacca.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^  -o $@

povacca.o: pomain.o poadd.o pomul.o popop.o
	$(LD) -r -T bigobj.lds $^ -o $@
