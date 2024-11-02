CC = gcc
OBJS = main.o exe.o sudoku.o maxSubMatrix.o functions.o slidePuzzle.o
EXEC = hw1
DEBUG = -g
CFLAGS = -std=c99  -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
$(CC) $(OBJS) -lm -o $@

exe.o: exe.c exe.h sudoku.h functions.h maxSubMatrix.h slidePuzzle.h
functions.o: functions.c functions.h
main.o: main.c exe.h
maxSubMatrix.o: maxSubMatrix.c maxSubMatrix.h
slidePuzzle.o: slidePuzzle.c slidePuzzle.h functions.h
sudoku.o: sudoku.c sudoku.h

clean:
	rm -f $(EXEC) $(OBJS)
