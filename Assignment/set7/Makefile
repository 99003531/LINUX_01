all: gpipe gpipe1 gpipe2

gpipe: gpipe.c solution.h
	gcc -o gpipe.out gpipe.c -lrt
	
gpipe1: gpipe1.c solution.h
	gcc -o gpipe1.out gpipe1.c -lrt

gpipe2: gpipe2.c solution.h
	gcc -o gpipe2.out gpipe2.c -lrt
	
rungpipe:
	./gpipe.out

rungpipe1:
	./gpipe1.out

rungpipe2:
	./gpipe2.out

clean:
	rm -rf *.out *.o
