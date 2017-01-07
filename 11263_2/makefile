CC = gcc -std=c99
SAM = sample.in
Rm = rm -rf

main: main.o
	$(CC) -o $@ $?

main.o: main.c
	$(CC) -c $?

run: main
	./$? < ./$(SAM)

output: main
	./$? < ./$(SAM) > temp.out
	
diff: temp.out
	diff $? sample.out

clean:
	$(RM) main *.o temp.out 