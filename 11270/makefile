CC = gcc -std=c99
SAM = sample.in
RM = rm -rf

main: main.o function.o
	$(CC) -o $@ $?

main.o: main.c function.h
	$(CC) -c $?

function.o: function.h function.c 
	$(CC) -c $?

run: main
	./$? < ./$(SAM)

output: main
	./$? < ./$(SAM) > temp.out

diff:
	diff ./temp.out ./sample.out

clean:
	$(RM) temp.out main *.o