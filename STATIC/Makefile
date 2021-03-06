TARGET=all.out
OBJS=test.o src/mystring.o src/bit_set_reset.o src/myutils.o

TOPDIR=${PWD}
CFLAGS=-I${TOPDIR}/inc
LDFLAGS=-lmystring -lmyutils -lbit_set_reset
LIBPATH=${PWD}

all:sall.out

sall.out:test.o libmystring.a libmyutils.a libbit_set_reset.a
    gcc -L${LIBPATH} $< -o $@ ${LDFLAGS} -static
libmystring.a:src/mystring.o 
    ar rc $@ $^
libmyutils.a:src/myutils.o 
    ar rc $@ $^
libbit_set_reset.a:src/bit_set_reset.o 
    ar rc $@ $^
%.o:src/%.c inc/%.h

test.o: test.c inc/*.h

test:
    ./sall.out

clean:
    rm -rf *.a *.o src/*.o ${TARGET}
