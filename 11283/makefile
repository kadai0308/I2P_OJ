CC = gcc -std=c99
S_OUT = sample.out
S_IN = sample.in

main: main.o function.o
	$(CC) -o $@ $?

main.o: main.c function.h
	$(CC) -c $?

function.o: function.c function.h
	$(CC) -c $?

run: main
	./$? < ./$(S_IN)

output: main
	./$? < ./$(S_IN) > temp.out

diff:
	diff ./temp.out $(S_OUT)

clean:
	rm -rf temp.out main *.o