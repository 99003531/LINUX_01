TARGET=sall.out
OBJS=test.o src/mystring.o src/bit_set_reset.o src/myutils.o

TOPDIR=${PWD}
CFLAGS=-I${TOPDIR}/include
LDFLAGS=-lmystring -lmyutils -lbit_set_reset
LIBPATH=${PWD}

all:sall.out

sall.out:test.o libmystring.a libmyutils.a libbit_set_reset.a
    gcc -L${LIBPATH} $< -o $@ ${LDFLAGS} 
libmystring.a:src/mystring.o 
    ar rc $@ $^
libmyutils.a:src/myutils.o 
    ar rc $@ $^
libbit_set_reset.a:src/bit_set_reset.o 
    ar rc $@ $^
%.o:src/%.c include/%.h

test.o: test.c include/*.h

test:
    ./sall.out
