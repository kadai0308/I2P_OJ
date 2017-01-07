CC = gcc -std=c99
RM = rm -rf
SAM = sample.in

main: main.o
	$(CC) -o $@ $?

main.o: main.c
	$(CC) -c $?

run: main
	./$? < $(SAM)

clean:
	$(RM) main *.o