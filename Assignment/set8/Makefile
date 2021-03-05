all: writefunc readfunc

writefunc: writefunc.c 
	gcc -o writefunc.out writefunc.c -lpthread -lrt
	
readfunc: readfunc.c 
	gcc -o readfunc.out readfunc.c -lpthread -lrt
	
runreadfunc:
	./readfunc.out

runwritefunc:
	./writefunc.out

clean:
	rm -rf *.out *.o