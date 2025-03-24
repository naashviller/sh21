CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
REPORT = report_test
LIB = s21_decimal.a
GCOVFLAGS = -fprofile-arcs -ftest-coverage
ALL_FUNCTIONS = $(wildcard decimal/*.c)
OBJ_FUNCTIONS = $(patsubst %.c, %.o, $(ALL_FUNCTIONS))
TEST = $(wildcard tests/*.c)
OS = $(shell uname)

ifeq ($(OS), Linux)
	LIBFLAGS = -lcheck -lpthread -lrt -lm -lsubunit $(GCOVFLAGS)
endif

ifeq ($(OS), Darwin)
	LIBFLAGS = -lcheck
endif

all: clean s21_decimal.a

s21_decimal.a: clean $(OBJ_FUNCTIONS)
	ar rc $(LIB) $(OBJ_FUNCTIONS)
	ranlib $(LIB)
	rm -rf *.o

test: clean s21_decimal.a
	$(CC) $(CFLAGS) $(TEST) $(ALL_FUNCTIONS) $(LIBFLAGS) s21_decimal.a -o $(REPORT) --coverage
	./$(REPORT)

gcov_report: clean test
#	chmod +x *
	lcov -t "report_test" -o report_test.info --no-external -c -d .
	genhtml -o report report_test.info
	open ./report/index.html

leaks: test
	CK_FORK=no leaks --atExit -- ./$(REPORT)

valgrind: test
	valgrind --tool=memcheck --leak-check=yes ./$(REPORT)
	valgrind -s --tool=memcheck --leak-check=yes ./$(REPORT)
	
clang:
	clang-format -style=Google -n *.h */*.c */*.h
	
style:
	clang-format -style=Google -i *.h */*.c */*.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem ${ALL_FUNCTIONS} ${TEST}

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
	rm -rf decimal/*.o
	rm -rf s21_decimal.a
	rm -rf *.gcno *.gcda *.gcov *.info
	rm -rf report $(REPORT)
	
rebuild: clean all
