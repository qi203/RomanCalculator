CC= gcc -I include

VPATH = lib test

# Compiler flags set to most strict
CFLAGS = -Wall -g

# Make sure the compiler knows where the libary lives
LIBFLAGS = -L./lib

# Libraries needed for this project (including the calculator library)
LIBS = -lrt -lm -lcalc

# Make sure we have the right versions to support check

PKG_CONFIG = $(shell which pkg-config)
ifneq ($(PKG_CONFIG), "")
CFLAGS += $(shell $(PKG_CONFIG) --cflags check)
LIBS += $(shell $(PKG_CONFIG) --libs check)
endif

defaut : test

libcalc.a: calc.o
	cd lib;make

check_calc.o: check_calc.c
	cd test;make

test:	check_calc.o libcalc.a
	cd test;make
	cd lib;make
	$(CC) $(CFLAGS) -o check_calc test/check_calc.o -pthread $(LIBFLAGS) $(LIBS)
# Now run the tests
	./check_calc

clean:
	-cd test;make clean
	-cd lib;make clean
	-rm check_calc  *.o


