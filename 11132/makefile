CC = gcc -std=c99
EXE = main
RM = rm -rf
SAM = sample.in


main: main.o
	$(CC) -o $(EXE) main.o

main.o: main.c 
	$(CC) -c main.c

run: $(EXE)
	./$(EXE) < $(SAM)

clean: 
	rm $(EXE) *.o