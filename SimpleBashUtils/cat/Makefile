CC = gcc
CFLAG = -Wall -Werror -Wextra

all: s21_cat

s21_cat: s21_cat.o cat_flags.o
	$(CC) $(CFLAG) s21_cat.o cat_flags.o -o s21_cat
		
cat_flags.o: cat_flags.c cat_flags.h s21_cat.h
		$(CC) $(CFLAG) -c cat_flags.c
		
s21_cat.o: s21_cat.c s21_cat.h
	$(CC) $(CFLAG) -c s21_cat.c

clean:
	rm -rf *.o
	
rebuild: clean all
