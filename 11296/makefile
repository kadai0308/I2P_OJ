CC = gcc -std=c99
SAM = sample.in
Rm = rm -rf

main: main.o function.o
	$(CC) -o $@ $?

main.o: main.c function.h
	$(CC) -c $?

function.o: function.c function.h
	$(CC) -c $?

run: main
	./$? < $(SAM)

clean:
	$(RM) main *.o