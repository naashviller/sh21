CC = gcc
CFLAG = -Wall -Werror -Wextra

all: s21_grep

s21_grep: s21_grep.o grep_flags.o
	$(CC) $(CFLAG) s21_grep.o grep_flags.o -o s21_grep
	
s21_grep.o: s21_grep.c s21_grep.h
	$(CC) $(CFLAG) -c s21_grep.c
	
grep_flags.o: grep_flags.c grep_flags.h s21_grep.h
	$(CC) $(CFLAG) -c grep_flags.c
	
clean:
	rm -rf *.o
	
rebuild: clean all
