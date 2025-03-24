#include "s21_matrix_test.h"

START_TEST(s21_eq_matrix_test_1) {
  matrix_t A_1;
  ck_assert_int_eq(s21_eq_matrix(&A_1, NULL), FAILURE);

  matrix_t B_1;
  ck_assert_int_eq(s21_eq_matrix(NULL, &B_1), FAILURE);

  ck_assert_int_eq(s21_eq_matrix(NULL, NULL), FAILURE);

  matrix_t A_2;
  A_2.rows = 0;
  A_2.columns = 1;
  matrix_t B_2;
  B_2.rows = 1;
  B_2.columns = 1;
  ck_assert_int_eq(s21_eq_matrix(&A_2, &B_2), FAILURE);

  matrix_t A_3;
  A_3.rows = 1;
  A_3.columns = 1;
  matrix_t B_3;
  B_3.rows = 1;
  B_3.columns = 0;
  ck_assert_int_eq(s21_eq_matrix(&A_3, &B_3), FAILURE);

  matrix_t A_4;
  A_4.rows = 1;
  A_4.columns = 1;
  matrix_t B_4;
  B_4.rows = 1;
  B_4.columns = 2;
  ck_assert_int_eq(s21_eq_matrix(&A_4, &B_4), FAILURE);
}
END_TEST

START_TEST(s21_eq_matrix_test_2) {
  matrix_t A_1;
  s21_create_matrix(2, 2, &A_1);
  matrix_t B_1;
  s21_create_matrix(2, 2, &B_1);

  A_1.matrix[0][0] = 1.0;
  A_1.matrix[0][1] = 2.0;
  A_1.matrix[1][0] = 3.0;
  A_1.matrix[1][1] = 4.0;

  B_1.matrix[0][0] = 1.0;
  B_1.matrix[0][1] = 2.0;
  B_1.matrix[1][0] = 3.0;
  B_1.matrix[1][1] = 4.0;

  ck_assert_int_eq(s21_eq_matrix(&A_1, &B_1), SUCCESS);
  s21_remove_matrix(&A_1);
  s21_remove_matrix(&B_1);

  matrix_t A_2;
  s21_create_matrix(2, 2, &A_2);
  matrix_t B_2;
  s21_create_matrix(2, 2, &B_2);

  A_2.matrix[0][0] = 1.0;
  A_2.matrix[0][1] = 2.0;
  A_2.matrix[1][0] = 3.0;
  A_2.matrix[1][1] = 4.12345670;

  B_2.matrix[0][0] = 1.0;
  B_2.matrix[0][1] = 2.0;
  B_2.matrix[1][0] = 3.0;
  B_2.matrix[1][1] = 4.12345678;

  ck_assert_int_eq(s21_eq_matrix(&A_2, &B_2), SUCCESS);
  s21_remove_matrix(&A_2);
  s21_remove_matrix(&B_2);

  matrix_t A_3;
  s21_create_matrix(2, 2, &A_3);
  matrix_t B_3;
  s21_create_matrix(2, 2, &B_3);

  A_3.matrix[0][0] = 1.0;
  A_3.matrix[0][1] = 2.0;
  A_3.matrix[1][0] = 3.0;
  A_3.matrix[1][1] = 4.0;

  B_3.matrix[0][0] = 1.0;
  B_3.matrix[0][1] = -2.0;
  B_3.matrix[1][0] = 3.0;
  B_3.matrix[1][1] = 4.0;

  ck_assert_int_eq(s21_eq_matrix(&A_3, &B_3), FAILURE);
  s21_remove_matrix(&A_3);
  s21_remove_matrix(&B_3);

  matrix_t A_4;
  s21_create_matrix(2, 2, &A_4);
  matrix_t B_4;
  s21_create_matrix(2, 2, &B_4);

  A_4.matrix[0][0] = 1.0;
  A_4.matrix[0][1] = 2.0;
  A_4.matrix[1][0] = 3.0;
  A_4.matrix[1][1] = 4.1234567;

  B_4.matrix[0][0] = 1.0;
  B_4.matrix[0][1] = 2.0;
  B_4.matrix[1][0] = 3.0;
  B_4.matrix[1][1] = 4.1234560;

  ck_assert_int_eq(s21_eq_matrix(&A_4, &B_4), FAILURE);
  s21_remove_matrix(&A_4);
  s21_remove_matrix(&B_4);
}
END_TEST

Suite *suite(void) {
  Suite *suite = suite_create("\033[32m s21_eq_matrix_test \033[0m");
  TCase *tcase = tcase_create("core");

  tcase_add_test(tcase, s21_eq_matrix_test_1);
  tcase_add_test(tcase, s21_eq_matrix_test_2);

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