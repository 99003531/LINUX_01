Build: test.c src/mystring.c src/myutils.c src/bit_set_reset.c
	gcc test.c src/mystring.c src/myutils.c src/bit_set_reset.c -Iinc

run:Build
	./a.out
