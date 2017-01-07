CC = gcc -std=c99
SAM = sample.in
RM = rm -rf

main: main.o
	$(CC) -o $@ $?

main.o: main.c
	$(CC) -c $?

run: main
	./main < $(SAM)

clean:
	$(RM) main *.o