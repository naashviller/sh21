CC = gcc
CFLAGS = -Wall -Werror -Wextra
#GCOVFLAGS = -fprofile-arcs -ftest-coverage
OS = $(shell uname)

ifeq ($(OS), Darwin)
	LIBFLAGS = -lcheck
	MYPATH = -I /opt/homebrew/include
else
	LIBFLAGS = -lcheck -lsubunit -lpthread -lrt -lm
endif

all: clean s21_string.a test gcov_report

s21_string.a: s21_string_fuction.o s21_string_sharp.o s21_string_print.o s21_string_scan.o s21_struct.o
	ar rcs s21_string.a s21_string_fuction.o s21_string_sharp.o s21_string_print.o s21_string_scan.o s21_struct.o
	ranlib s21_string.a

s21_string_fuction.o: s21_string_fuction.c s21_string_fuction.h s21_string.h
	$(CC) $(CFLAGS) -c s21_string_fuction.c

s21_string_sharp.o: s21_string_sharp.c s21_string_sharp.h s21_string.h
	$(CC) $(CFLAGS) -c s21_string_sharp.c
		
s21_string_print.o: s21_string_print.c s21_string_print.h s21_string.h
	$(CC) $(CFLAGS) -c s21_string_print.c
	
s21_string_scan.o: s21_string_scan.c s21_string_scan.h s21_string.h
	$(CC) $(CFLAGS) -c s21_string_scan.c
	
s21_struct.o: s21_struct.c s21_struct.h s21_string.h
	$(CC) $(CFLAGS) -c s21_struct.c
	
test: s21_string.a main_test.o
	$(CC) $(CFLAGS) main_test.o $(LIBFLAGS) s21_string.a -o test
	./test
	
main_test.o: tests/main_test.c tests/main_test.h
	$(CC) $(CFLAGS) -c tests/main_test.c $(MYPATH)

gcov_report: s21_string.a main_test.o
	$(CC) $(CFLAGS) --coverage tests/main_test.c $(MYPATH) $(LIBFLAGS) s21_string.a -o gcov_test
#	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report gcov_test.info
	open ./report/index.html
		
leaks: test
	CK_FORK=no leaks --atExit -- ./test
	
clang:
	clang-format -style=Google -n *.c *.h */*.c */*.h

tostyle:
	clang-format -style=Google -i *.c *.h */*.c */*.h
		
brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

lcov:
ifeq ($(OS),Linux)
	sudo apt install lcov
endif
ifeq ($(OS),Darwin)
	brew install lcov
endif

clean:
	rm -rf *.o *.a test gcov_test report main_test.gcda main_test.gcno gcov_test.info
	
rebuild: clean all

