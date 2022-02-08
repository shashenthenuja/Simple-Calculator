CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
OBJ = main.o terminal.o interface.o fileIO.o logic.o linkedlist.o
EXEC = calculator

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c terminal.h fileIO.h interface.h logic.h linkedlist.h
	$(CC) $(CFLAGS) main.c -c

fileIO.c : fileIO.c fileIO.h
	$(CC) $(CFLAGS) fileIO.c -c

terminal.c : terminal.c terminal.h
	$(CC) $(CFLAGS) terminal.c -c

interface.c : interface.c interface.h
	$(CC) $(CFLAGS) interface.c -c

logic.c : logic.c logic.h
	$(CC) $(CFLAGS) logic.c -c

linkedlist.c : linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) linkedlist.c -c

clean :
	rm -f $(EXEC) $(OBJ)