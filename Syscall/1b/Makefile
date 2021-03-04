PROJECT_NAME =TASK2

SRC = src/count.c\
main.c

INC = -Iinc

$(PROJECT_NAME).out : $(SRC)
	gcc $^ -o $@ $(INC)

run : $(PROJECT_NAME).out
	./$^

clean:
	rm -rf *.o *.out
