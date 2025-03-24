CC=gcc
CFLAGS=-Wall -Werror -Wextra -ggdb -std=c11
GCOVFLAGS=-fprofile-arcs -ftest-coverage 

OS=$(shell uname -s)
ifeq ($(OS),Linux)
CHECKFLAGS=-lcheck -lsubunit -lrt -lpthread -lm -lgcov --coverage
endif
# ПРОВЕРИТЬ на маке
ifeq ($(OS),Darwin)   
CHECKFLAGS=-lcheck -lgcov --coverage
endif

STATICLIB=s21_matrix.a
DIROBJ=./obj
DIRFUNCTESTS=./tests
DIRGCOV=./gcov
DIRGENHTML=./genhtml

all: $(STATICLIB) test gcov_report 

build: all

rebuild: clean all

$(STATICLIB):
	$(CC) $(CFLAGS) -c ./s21_matrix_func/*.c 
	ar r $(STATICLIB) *.o
	rm -f *.o

test: $(STATICLIB)
	$(CC) $(CFLAGS) -c ./s21_matrix_func/*.c $(GCOVFLAGS) 
	$(CC) $(CFLAGS) -c ./s21_matrix_func_tests/*.c
	mkdir -p $(DIROBJ)  
	mv -f *.o $(DIROBJ)

	$(CC) $(CFLAGS) $(DIROBJ)/s21_matrix_test.o $(DIROBJ)/s21_additional_func.o $(STATICLIB) -o s21_matrix_test $(CHECKFLAGS)
	$(CC) $(CFLAGS) $(DIROBJ)/s21_create_matrix_test.o $(DIROBJ)/s21_create_matrix.o $(STATICLIB) -o s21_create_matrix_test $(CHECKFLAGS)
	$(CC) $(CFLAGS) $(DIROBJ)/s21_remove_matrix_test.o $(DIROBJ)/s21_remove_matrix.o $(STATICLIB) -o s21_remove_matrix_test $(CHECKFLAGS)
	$(CC) $(CFLAGS) $(DIROBJ)/s21_eq_matrix_test.o $(DIROBJ)/s21_eq_matrix.o $(STATICLIB) -o s21_eq_matrix_test $(CHECKFLAGS)
	$(CC) $(CFLAGS) $(DIROBJ)/s21_sum_matrix_test.o $(DIROBJ)/s21_sum_matrix.o $(STATICLIB) -o s21_sum_matrix_test $(CHECKFLAGS)
	$(CC) $(CFLAGS) $(DIROBJ)/s21_sub_matrix_test.o $(DIROBJ)/s21_sub_matrix.o $(STATICLIB) -o s21_sub_matrix_test $(CHECKFLAGS)
	$(CC) $(CFLAGS) $(DIROBJ)/s21_mult_number_test.o $(DIROBJ)/s21_mult_number.o $(STATICLIB) -o ss21_mult_number_test $(CHECKFLAGS)
	$(CC) $(CFLAGS) $(DIROBJ)/s21_mult_matrix_test.o $(DIROBJ)/s21_mult_matrix.o $(STATICLIB) -o s21_mult_matrix_test $(CHECKFLAGS)
	$(CC) $(CFLAGS) $(DIROBJ)/s21_transpose_test.o $(DIROBJ)/s21_transpose.o $(STATICLIB) -o s21_transpose_test $(CHECKFLAGS)
	$(CC) $(CFLAGS) $(DIROBJ)/s21_calc_complements_test.o $(DIROBJ)/s21_calc_complements.o $(STATICLIB) -o s21_calc_complements_test $(CHECKFLAGS)
	$(CC) $(CFLAGS) $(DIROBJ)/s21_determinant_test.o $(DIROBJ)/s21_determinant.o $(STATICLIB) -o s21_determinant_test $(CHECKFLAGS)
	$(CC) $(CFLAGS) $(DIROBJ)/s21_inverse_matrix_test.o $(DIROBJ)/s21_inverse_matrix.o $(STATICLIB) -o s21_inverse_matrix_test $(CHECKFLAGS)

	mkdir -p $(DIRFUNCTESTS)  
	mv -f *_test $(DIRFUNCTESTS) 
	make run_test

run_test:
	$(DIRFUNCTESTS)/s21_matrix_test
	$(DIRFUNCTESTS)/s21_create_matrix_test
	$(DIRFUNCTESTS)/s21_remove_matrix_test
	$(DIRFUNCTESTS)/s21_eq_matrix_test
	$(DIRFUNCTESTS)/s21_sum_matrix_test
	$(DIRFUNCTESTS)/s21_sub_matrix_test
	$(DIRFUNCTESTS)/ss21_mult_number_test
	$(DIRFUNCTESTS)/s21_mult_matrix_test
	$(DIRFUNCTESTS)/s21_transpose_test
	$(DIRFUNCTESTS)/s21_calc_complements_test
	$(DIRFUNCTESTS)/s21_determinant_test
	$(DIRFUNCTESTS)/s21_inverse_matrix_test

gcov_report:
	mkdir -p $(DIRGCOV)
	gcov ./s21_matrix_func/*.c -o ./
	mv -f *.gcov $(DIRGCOV)
	mv -f *.gcda $(DIRGCOV)
	mv -f *.gcno $(DIRGCOV)
	lcov -d $(DIRGCOV) -c -o ./html.info
	genhtml -o $(DIRGENHTML) html.info
	open $(DIRGENHTML)/index.html
	
check:
	cp ../materials/linters/.clang-format ./
	clang-format -n ./*.h
	clang-format -n ./s21_matrix_func/*.c
	clang-format -n ./s21_matrix_func_tests/*.c ./s21_matrix_func_tests/*.h
	rm -f .clang-format

clang_fix:
	cp ../materials/linters/.clang-format ./
	clang-format -i ./*.h
	clang-format -i ./s21_matrix_func/*.c
	clang-format -i ./s21_matrix_func_tests/*.c ./s21_matrix_func_tests/*.h
	rm -f .clang-format
	
valgrind: clean test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all $(DIRFUNCTESTS)/s21_matrix_test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all $(DIRFUNCTESTS)/s21_create_matrix_test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all $(DIRFUNCTESTS)/s21_remove_matrix_test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all $(DIRFUNCTESTS)/s21_eq_matrix_test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all $(DIRFUNCTESTS)/s21_sum_matrix_test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all $(DIRFUNCTESTS)/s21_sub_matrix_test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all $(DIRFUNCTESTS)/ss21_mult_number_test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all $(DIRFUNCTESTS)/s21_mult_matrix_test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all $(DIRFUNCTESTS)/s21_transpose_test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all $(DIRFUNCTESTS)/s21_calc_complements_test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all $(DIRFUNCTESTS)/s21_determinant_test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all $(DIRFUNCTESTS)/s21_inverse_matrix_test
	
clean:
	rm -f *.a
	rm -f *.gc*
	
	rm -drf $(DIROBJ)
	rm -drf $(DIRFUNCTESTS)
	rm -drf $(DIRGCOV)
	rm -drf $(DIRGENHTML)
	rm -f *.info