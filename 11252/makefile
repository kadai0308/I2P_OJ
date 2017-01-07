CC = gcc -std=c99
RM = rm -rf
SAM = sample.in

main: main.o function.o
	$(CC) -o $@ $?

main.o: main.c function.h
	$(CC) -c $?

function.o: function.h function.c
	$(CC) -c $?

run: main
	./$? < ./$(SAM)

clean:
	$(RM) main *.o