CC = gcc -std=c99
EXE = main
RM = rm -rf
SAM = sample.in

main: main.o function.o
	$(CC) -o $(EXE) $?

main.o: main.c function.h
	$(CC) -c main.c

function.o: function.c function.h
	$(CC) -c function.c

run: $(EXE)
	./$(EXE) < ./$(SAM)

clean:
	$(RM) $(EXE) *.o