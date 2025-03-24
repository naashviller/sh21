#include "s21_matrix_test.h"

START_TEST(s21_remove_matrix_test_1) {
  int rows = 0;
  int columns = 0;

  s21_remove_matrix(NULL);

  matrix_t A_1;
  rows = 0;
  columns = 1;
  s21_create_matrix(rows, columns, &A_1);

  matrix_t A_2;
  rows = 1;
  columns = 0;
  s21_create_matrix(rows, columns, &A_2);

  matrix_t A_3;
  rows = 0;
  columns = 0;
  s21_create_matrix(rows, columns, &A_3);
}
END_TEST

START_TEST(s21_remove_matrix_test_2) {
  int rows = 0;
  int columns = 0;

  matrix_t A_1;
  rows = 1;
  columns = 1;
  s21_create_matrix(rows, columns, &A_1);
  s21_remove_matrix(&A_1);
  ck_assert_ptr_null(A_1.matrix);
  ck_assert_int_eq(A_1.rows, 0);
  ck_assert_int_eq(A_1.columns, 0);

  matrix_t A_2;
  rows = 10;
  columns = 50;
  s21_create_matrix(rows, columns, &A_2);
  s21_remove_matrix(&A_2);
  ck_assert_ptr_null(A_2.matrix);
  ck_assert_int_eq(A_2.rows, 0);
  ck_assert_int_eq(A_2.columns, 0);

  matrix_t A_3;
  rows = 123;
  columns = 321;
  s21_create_matrix(rows, columns, &A_3);
  s21_remove_matrix(&A_3);
  ck_assert_ptr_null(A_3.matrix);
  ck_assert_int_eq(A_3.rows, 0);
  ck_assert_int_eq(A_3.columns, 0);
}
END_TEST

Suite *suite(void) {
  Suite *suite = suite_create("\033[32m s21_remove_matrix_test \033[0m");
  TCase *tcase = tcase_create("core");

  tcase_add_test(tcase, s21_remove_matrix_test_1);
  tcase_add_test(tcase, s21_remove_matrix_test_2);

  suite_add_tcase(suite, tcase);
  return suite;
}

void case_test_runner(Suite *suite, int *fail_count) {
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_NORMAL);
  *fail_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
}

int main(void) {
  int fail_count = 0;
  case_test_runner(suite(), &fail_count);

  return fail_count;
}