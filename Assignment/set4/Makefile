all: sender receiver

sender: sender.c 
	gcc -o sender.out sender.c -lrt
	
receiver: receiver.c 
	gcc -o receiver.out receiver.c -lrt
	
runreceiver:
	./receiver.out

runsender:
	./sender.out

clean:
	rm -rf *.out *.o