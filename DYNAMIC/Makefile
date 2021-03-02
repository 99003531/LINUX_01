TARGET=sall.out
OBJS=test.o src/mystring.o  src/bitmask.o src/myutils.o

TOPDIR=${PWD}
CFLAGS=-I${TOPDIR}/include
LDFLAGS=-lmystring -lmyutils -lmasking
LIBPATH=${PWD}

all:sall.out

sall.out:test.o libmystring.a libmyutils.a libmasking.a
    gcc -L${LIBPATH} $< -o $@ ${LDFLAGS} 
libMystring.a:src/mystring.o 
    ar rc $@ $^
libMyutils.a:src/myutils.o 
    ar rc $@ $^
libBitmask.a:src/bitmask.o 
    ar rc $@ $^
%.o:src/%.c include/%.h

test.o: test.c include/*.h

test:
    ./sall.out
