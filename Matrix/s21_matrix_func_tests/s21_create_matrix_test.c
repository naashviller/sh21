#include "s21_matrix_test.h"

START_TEST(s21_create_matrix_test_1) {
  int rows = 0;
  int columns = 0;

  rows = 1;
  columns = 1;
  ck_assert_int_eq(s21_create_matrix(rows, columns, NULL),
                   RETURN_ERROR_INCORRECT_MARIX_1);

  matrix_t A_1;
  rows = 1;
  columns = 0;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &A_1),
                   RETURN_ERROR_INCORRECT_MARIX_1);

  matrix_t A_2;
  rows = 0;
  columns = 1;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &A_2),
                   RETURN_ERROR_INCORRECT_MARIX_1);

  matrix_t A_3;
  rows = 0;
  columns = 0;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &A_3),
                   RETURN_ERROR_INCORRECT_MARIX_1);

  matrix_t A_4;
  rows = 0;
  columns = -1;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &A_4),
                   RETURN_ERROR_INCORRECT_MARIX_1);

  matrix_t A_5;
  rows = -1;
  columns = 0;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &A_5),
                   RETURN_ERROR_INCORRECT_MARIX_1);

  matrix_t A_6;
  rows = -1;
  columns = -1;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &A_6),
                   RETURN_ERROR_INCORRECT_MARIX_1);
}
END_TEST

START_TEST(s21_create_matrix_test_2) {
  int rows = 0;
  int columns = 0;

  matrix_t A_1;
  rows = 1;
  columns = 1;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &A_1), RETURN_OK_0);
  ck_assert_int_eq(A_1.rows, rows);
  ck_assert_int_eq(A_1.columns, columns);
  s21_remove_matrix(&A_1);

  matrix_t A_2;
  rows = 10;
  columns = 50;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &A_2), RETURN_OK_0);
  ck_assert_int_eq(A_2.rows, rows);
  ck_assert_int_eq(A_2.columns, columns);
  s21_remove_matrix(&A_2);

  matrix_t A_3;
  rows = 123;
  columns = 321;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &A_3), RETURN_OK_0);
  ck_assert_int_eq(A_3.rows, rows);
  ck_assert_int_eq(A_3.columns, columns);
  s21_remove_matrix(&A_3);
}
END_TEST

Suite *suite(void) {
  Suite *suite = suite_create("\033[32m s21_create_matrix_test \033[0m");
  TCase *tcase = tcase_create("core");

  tcase_add_test(tcase, s21_create_matrix_test_1);
  tcase_add_test(tcase, s21_create_matrix_test_2);

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