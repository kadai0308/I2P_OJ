CC = gcc -std=c99
EXE = main
RM = rm -rf
SAM = sample.in

main: main.o
	$(CC) -o $(EXE) $?

main.o: main.c
	$(CC) -c $?

run: $(EXE)
	./$? < ./$(SAM)

clean:
	$(RM) $(EXE) *.o