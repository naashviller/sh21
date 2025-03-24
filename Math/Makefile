CC = gcc
CF = clang-format -i
CFLAGS = -Wall -Werror -Wextra
TEST_LIBS = -lcheck -lm -lpthread
OBJECTS=s21_math.o
SOURSES=s21_math.c
GCOVFLAGS = -fprofile-arcs -ftest-coverage
OS = $(shell uname)

ifeq ($(OS), Darwin)
	TEST_LIBS=-lcheck
else
	TEST_LIBS=-lcheck -lsubunit -pthread -lrt -lm
endif

all: clean s21_math.a test gcov_report

s21_math.a: s21_math.o
	$(CC) -c $(SOURSES)
	ar rcs s21_math.a $(OBJECTS)

clean:
	rm -rf ./*.o ./*.a ./a.out gcov_test *.html *.css ./GcovReport ./*.gcno ./*.gcda ./report ./*.info ./math_o ./*.dSYM ./test_s21math test

test: tests/s21_math_unit_test.c s21_math.a
	$(CC) $(CFLAGS) -c tests/s21_math_unit_test.c -o test.o
	$(CC) test.o s21_math.a $(TEST_LIBS) -o test
	./test

gcov_report: s21_math.a 
	$(CC) $(CFLAGS) --coverage tests/s21_math_unit_test.c s21_math.c s21_math.a $(TEST_LIBS) -o gcov_test
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html

clang:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.c *.h
	clang-format -n tests/*.c
	rm -rf .clang-format

clang_fix:
	cp ../materials/linters/.clang-format ./
	clang-format -i *.c *.h
	clang-format -n tests/*.c
	rm -rf .clang-format


rebuild: clean all