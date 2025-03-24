#include "s21_test_decimal.h"
//-0 && 0
START_TEST(test_null_greater) {
  s21_decimal num, num1;
  num.bits[0] = 0b00000000000000000000000000000000;
  num.bits[1] = 0b00000000000000000000000000000000;
  num.bits[2] = 0b00000000000000000000000000000000;
  num.bits[3] = 0b10000000000000000000000000000000;

  num1.bits[0] = 0b00000000000000000000000000000000;
  num1.bits[1] = 0b00000000000000000000000000000000;
  num1.bits[2] = 0b00000000000000000000000000000000;
  num1.bits[3] = 0b00000000000000000000000000000000;

  ck_assert_int_eq(0, s21_is_greater(num, num1));
  ck_assert_int_eq(0, s21_is_less(num, num1));
  ck_assert_int_eq(1, s21_is_equal(num, num1));
  ck_assert_int_eq(1, s21_is_greater_or_equal(num, num1));
  ck_assert_int_eq(1, s21_is_less_or_equal(num, num1));
  ck_assert_int_eq(0, s21_is_not_equal(num, num1));
}
END_TEST
// 0 && -0
START_TEST(test_null_greater_2) {
  s21_decimal num, num1;
  num.bits[0] = 0b00000000000000000000000000000000;
  num.bits[1] = 0b00000000000000000000000000000000;
  num.bits[2] = 0b00000000000000000000000000000000;
  num.bits[3] = 0b00000000000000000000000000000000;

  num1.bits[0] = 0b00000000000000000000000000000000;
  num1.bits[1] = 0b00000000000000000000000000000000;
  num1.bits[2] = 0b00000000000000000000000000000000;
  num1.bits[3] = 0b10000000000000000000000000000000;

  ck_assert_int_eq(0, s21_is_greater(num, num1));
  ck_assert_int_eq(0, s21_is_less(num, num1));
  ck_assert_int_eq(1, s21_is_equal(num, num1));
  ck_assert_int_eq(1, s21_is_greater_or_equal(num, num1));
  ck_assert_int_eq(1, s21_is_less_or_equal(num, num1));
  ck_assert_int_eq(0, s21_is_not_equal(num, num1));
}
END_TEST
//-0 && -0
START_TEST(test_null_greater_3) {
  s21_decimal num, num1;
  num.bits[0] = 0b00000000000000000000000000000000;
  num.bits[1] = 0b00000000000000000000000000000000;
  num.bits[2] = 0b00000000000000000000000000000000;
  num.bits[3] = 0b10000000000000000000000000000000;

  num1.bits[0] = 0b00000000000000000000000000000000;
  num1.bits[1] = 0b00000000000000000000000000000000;
  num1.bits[2] = 0b00000000000000000000000000000000;
  num1.bits[3] = 0b10000000000000000000000000000000;

  ck_assert_int_eq(0, s21_is_greater(num, num1));
  ck_assert_int_eq(0, s21_is_less(num, num1));
  ck_assert_int_eq(1, s21_is_equal(num, num1));
  ck_assert_int_eq(1, s21_is_greater_or_equal(num, num1));
  ck_assert_int_eq(1, s21_is_less_or_equal(num, num1));
  ck_assert_int_eq(0, s21_is_not_equal(num, num1));
}
END_TEST

/*--------- IS LESS '<' ---------*/
START_TEST(s21_is_less_test_1) {
  s21_decimal test_v_1, test_v_2;
  test_v_1.bits[0] = 0b00000000000000000000000001000000;
  test_v_1.bits[1] = 0b00000000000000000000000000000000;
  test_v_1.bits[2] = 0b00000000000000000000000000000000;
  test_v_1.bits[3] = 0b00000000000000000000000000000000;

  test_v_2.bits[0] = 0b00000000000000000000000000000100;
  test_v_2.bits[1] = 0b00000000000000000000000000000000;
  test_v_2.bits[2] = 0b00000000000000000000000000000000;
  test_v_2.bits[3] = 0b10000000000000000000000000000000;

  ck_assert_int_eq(s21_is_less(test_v_1, test_v_2), 0);
}
END_TEST

START_TEST(s21_is_less_test_2) {
  s21_decimal num = {{0, 0, 0, 0}};
  s21_decimal num1 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(num, num1), 0);
}
END_TEST

START_TEST(s21_is_less_test_3) {
  s21_decimal num = {{100, 0, 0, 0}};
  s21_decimal num1 = {{120, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(num, num1), 1);
}
END_TEST

START_TEST(s21_is_less_test_4) {
  s21_decimal num = {{39999, 0, 0, 0}};
  s21_decimal num1 = {{40000, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(num, num1), 1);
}
END_TEST

START_TEST(s21_is_less_test_5) {
  s21_decimal num = {{26000, 0, 0, 0}};
  s21_decimal num1 = {{25999, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(num, num1), 0);
}
END_TEST

START_TEST(s21_is_less_test_6) {
  s21_decimal num = {{20000, 0, 0, 0}};
  s21_decimal num1 = {{2000, 0, 0, 2147483648}};
  ck_assert_int_eq(s21_is_less(num, num1), 0);
}
END_TEST

START_TEST(s21_is_less_test_7) {
  s21_decimal test_v_1 = {{19993, 1, 0, 2147483648}};
  s21_decimal test_v_2 = {{19993, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(test_v_1, test_v_2), 1);
}
END_TEST

START_TEST(s21_is_less_test_9) {
  s21_decimal num = {{0, 10, 0, 0}};
  s21_decimal num1 = {{40000, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(num, num1), 0);
}
END_TEST

START_TEST(s21_is_less_test_10) {
  s21_decimal num = {{40000, 1, 0, 0b10000000111111110000000000000000}};
  s21_decimal num1 = {{40000, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(num, num1), 1);
}
END_TEST

// /* --------- IS LESS OR EQUAL '<=' ---------*/
START_TEST(s21_is_less_or_equal_test_1) {
  s21_decimal num = {{0, 0, 0, 0}};
  s21_decimal num1 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(num, num1), 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_2) {
  s21_decimal num = {{99999, 0, 0, 0}};
  s21_decimal num1 = {{100000, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(num, num1), 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_3) {
  s21_decimal num = {{99999, 0, 0, 0}};
  s21_decimal num1 = {{99999, 0, 0, 2147483648}};
  ck_assert_int_eq(s21_is_less_or_equal(num, num1), 0);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_4) {
  s21_decimal num = {{99999, 0, 0, 0}};
  s21_decimal num1 = {{99999, 0, 0, 300000}};
  ck_assert_int_eq(s21_is_less_or_equal(num, num1), 0);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_5) {
  s21_decimal num = {{0, 99, 0, 0}};
  s21_decimal num1 = {{0, 99, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(num, num1), 1);
}
END_TEST
/*--------- IS GREATER '>' ---------*/
START_TEST(s21_is_greater_test_1) {
  s21_decimal num, num1;
  s21_from_float_to_decimal(9.01999, &num);
  s21_from_float_to_decimal(9.01, &num1);
  ck_assert_int_eq(s21_is_greater(num, num1), 1);
  ck_assert_int_eq(s21_is_greater(num1, num), 0);
}
END_TEST

START_TEST(s21_is_greater_test_2) {
  s21_decimal num, num1;
  s21_from_float_to_decimal(-9.01999, &num);
  s21_from_float_to_decimal(-9.01, &num1);
  ck_assert_int_eq(s21_is_greater(num, num1), 0);
  ck_assert_int_eq(s21_is_greater(num1, num), 1);
}
END_TEST

START_TEST(s21_is_greater_test_3) {
  s21_decimal num, num1;
  s21_from_float_to_decimal(9.01999, &num);
  s21_from_float_to_decimal(-9.01, &num1);
  ck_assert_int_eq(s21_is_greater(num, num1), 1);
  ck_assert_int_eq(s21_is_greater(num1, num), 0);
}
END_TEST

START_TEST(s21_is_greater_test_4) {
  s21_decimal num, num1;
  s21_from_float_to_decimal(0.0, &num);
  s21_from_float_to_decimal(0.0, &num1);
  ck_assert_int_eq(s21_is_greater(num, num1), 0);
}
END_TEST

/*--------- IS GREATER OR EQUAL'>=' ---------*/
START_TEST(test_s21_is_greater_or_equal_1) {
  s21_decimal test_v_1 = {{0, 0, 0, 0}};
  s21_decimal test_v_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(test_v_1, test_v_2), 1);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_2) {
  s21_decimal test_v_1 = {{20000, 0, 0, 0}};
  s21_decimal test_v_2 = {{20001, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(test_v_1, test_v_2), 0);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_3) {
  s21_decimal test_v_1 = {{20000, 0, 0, 0}};
  s21_decimal test_v_2 = {{20000, 0, 0, 300000}};
  ck_assert_int_eq(s21_is_greater_or_equal(test_v_1, test_v_2), 1);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_4) {
  s21_decimal test_v_1 = {{20000, 0, 0, 0}};
  s21_decimal test_v_2 = {{20000, 0, 0, 2147483648}};
  ck_assert_int_eq(s21_is_greater_or_equal(test_v_1, test_v_2), 1);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal_5) {
  s21_decimal test_v_1 = {{20000, 0, 0, 0}};
  s21_decimal test_v_2 = {{20000, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(test_v_1, test_v_2), 1);
}
END_TEST

// /*--------- IS EQUAL'==' ---------*/
START_TEST(test_s21_is_equal_1) {
  s21_decimal test_v_1 = {{0, 0, 0, 0}};
  s21_decimal test_v_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_equal(test_v_1, test_v_2), 1);
}
END_TEST

START_TEST(test_s21_is_equal_2) {
  s21_decimal test_v_1 = {{20000, 0, 0, 0}};
  s21_decimal test_v_2 = {{20001, 0, 0, 0}};
  ck_assert_int_eq(s21_is_equal(test_v_1, test_v_2), 0);
}
END_TEST

START_TEST(test_s21_is_equal_3) {
  s21_decimal test_v_1 = {{4999, 0, 0, 0}};
  s21_decimal test_v_2 = {{4999, 0, 0, 2147483648}};
  ck_assert_int_eq(s21_is_equal(test_v_1, test_v_2), 0);
}
END_TEST

START_TEST(test_s21_is_equal_4) {
  s21_decimal test_v_1 = {{20000, 0, 0, 0}};
  s21_decimal test_v_2 = {{20000, 0, 0, 300000}};
  ck_assert_int_eq(s21_is_equal(test_v_1, test_v_2), 0);
}
END_TEST

START_TEST(test_s21_is_equal_5) {
  s21_decimal test_v_1 = {{20000, 1, 0, 0}};
  s21_decimal test_v_2 = {{20000, 0, 2, 0}};
  ck_assert_int_eq(s21_is_equal(test_v_1, test_v_2), 0);
}
END_TEST

START_TEST(test_s21_is_equal_6) {
  s21_decimal test_v_1 = {{-20000, 0, 0, 0}};
  s21_decimal test_v_2 = {{20001, 0, 0, 0}};
  ck_assert_int_eq(s21_is_equal(test_v_1, test_v_2), 0);
}
END_TEST

START_TEST(test_s21_is_equal_7) {
  s21_decimal test_v_1 = {{-20000, 0, 0, 0}};
  s21_decimal test_v_2 = {{-20001, 0, 0, 0}};
  ck_assert_int_eq(s21_is_equal(test_v_1, test_v_2), 0);
}
END_TEST

/*------------- IS NOT EQUAL '!=' --------------*/
START_TEST(test_s21_is_not_equal_1) {
  s21_decimal test_v_1 = {{0, 0, 0, 0}};
  s21_decimal test_v_2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_not_equal(test_v_1, test_v_2), 0);
}
END_TEST

START_TEST(test_s21_is_not_equal_2) {
  s21_decimal test_v_1 = {{20000, 0, 0, 0}};
  s21_decimal test_v_2 = {{20001, 0, 0, 0}};
  ck_assert_int_eq(s21_is_not_equal(test_v_1, test_v_2), 1);
}
END_TEST

START_TEST(test_s21_is_not_equal_3) {
  s21_decimal test_v_1 = {{5000, 0, 0, 0}};
  s21_decimal test_v_2 = {{5000, 0, 0, 2147483648}};
  ck_assert_int_eq(s21_is_not_equal(test_v_1, test_v_2), 1);
}
END_TEST

START_TEST(test_s21_is_not_equal_4) {
  s21_decimal test_v_1 = {{20000, 0, 0, 0}};
  s21_decimal test_v_2 = {{20000, 0, 0, 300000}};
  ck_assert_int_eq(s21_is_not_equal(test_v_1, test_v_2), 1);
}
END_TEST

START_TEST(test_s21_is_not_equal_5) {
  s21_decimal test_v_1 = {{20000, 1, 0, 0}};
  s21_decimal test_v_2 = {{20000, 0, 2, 0}};
  ck_assert_int_eq(s21_is_not_equal(test_v_1, test_v_2), 1);
}
END_TEST

START_TEST(test_s21_is_not_equal_6) {
  s21_decimal test_v_1 = {{-20000, 0, 0, 0}};
  s21_decimal test_v_2 = {{20000, 0, 0, 0}};
  ck_assert_int_eq(s21_is_not_equal(test_v_1, test_v_2), 1);
}
END_TEST

Suite *lorentmi_operators(void) {
  Suite *s = suite_create("\033[45m-=OPERATORS=-\033[0m");
  TCase *tc = tcase_create("OPERATORS");

  suite_add_tcase(s, tc);

  /*-------------NULL---------------*/
  tcase_add_test(tc, test_null_greater);
  tcase_add_test(tc, test_null_greater_2);
  tcase_add_test(tc, test_null_greater_3);
  /*--------- IS LESS '<' ---------*/
  tcase_add_test(tc, s21_is_less_test_1);
  tcase_add_test(tc, s21_is_less_test_2);
  tcase_add_test(tc, s21_is_less_test_3);
  tcase_add_test(tc, s21_is_less_test_4);
  tcase_add_test(tc, s21_is_less_test_5);
  tcase_add_test(tc, s21_is_less_test_6);
  tcase_add_test(tc, s21_is_less_test_7);
  tcase_add_test(tc, s21_is_less_test_9);
  tcase_add_test(tc, s21_is_less_test_10);
  /* --------- IS LESS OR EQUAL '<=' ---------*/
  tcase_add_test(tc, s21_is_less_or_equal_test_1);
  tcase_add_test(tc, s21_is_less_or_equal_test_2);
  tcase_add_test(tc, s21_is_less_or_equal_test_3);
  tcase_add_test(tc, s21_is_less_or_equal_test_4);
  tcase_add_test(tc, s21_is_less_or_equal_test_5);
  /*--------- IS GREATER '>' ---------*/
  tcase_add_test(tc, s21_is_greater_test_1);
  tcase_add_test(tc, s21_is_greater_test_2);
  tcase_add_test(tc, s21_is_greater_test_3);
  tcase_add_test(tc, s21_is_greater_test_4);
  /*--------- IS GREATER OR EQUAL'>=' ---------*/
  tcase_add_test(tc, test_s21_is_greater_or_equal_1);
  tcase_add_test(tc, test_s21_is_greater_or_equal_2);
  tcase_add_test(tc, test_s21_is_greater_or_equal_3);
  tcase_add_test(tc, test_s21_is_greater_or_equal_4);
  tcase_add_test(tc, test_s21_is_greater_or_equal_5);
  /*--------- IS EQUAL'==' ---------*/
  tcase_add_test(tc, test_s21_is_equal_1);
  tcase_add_test(tc, test_s21_is_equal_2);
  tcase_add_test(tc, test_s21_is_equal_3);
  tcase_add_test(tc, test_s21_is_equal_4);
  tcase_add_test(tc, test_s21_is_equal_5);
  tcase_add_test(tc, test_s21_is_equal_6);
  tcase_add_test(tc, test_s21_is_equal_7);
  /*------------- IS NOT EQUAL '!=' -------*/
  tcase_add_test(tc, test_s21_is_not_equal_1);
  tcase_add_test(tc, test_s21_is_not_equal_2);
  tcase_add_test(tc, test_s21_is_not_equal_3);
  tcase_add_test(tc, test_s21_is_not_equal_4);
  tcase_add_test(tc, test_s21_is_not_equal_5);
  tcase_add_test(tc, test_s21_is_not_equal_6);

  suite_add_tcase(s, tc);
  return s;
}
