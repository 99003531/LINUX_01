all: server client

server: server.c cliser.h
	gcc -o server.out server.c -lrt
	
client: client.c cliser.h
	gcc -o client.out client.c -lrt
	
runclient:
	./client.out

runserver:
	./server.out

clean:
	rm -rf *.out *.o