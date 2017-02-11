CC=gcc -I ../include

CFLAGS=-Wall -c

# Make sure we have the right check, based on how it was installed
PKG_CONFIG = $(shell which pkg-config)
ifneq ($(PKG_CONFIG), "")
CFLAGS += $(shell $(PKG_CONFIG) --cflags check)
endif

all: calc.o
	$(CC) $(INCLUDES) $(CFLAGS) calc.c
	ar -rcs libcalc.a calc.o
clean:
	$(RM) libcalc.a calc.o
