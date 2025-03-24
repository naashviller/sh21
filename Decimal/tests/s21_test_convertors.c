#include "s21_test_decimal.h"

START_TEST(test_s21_int_to_decimal_1) {
  s21_decimal dst = {0}, origin = {0};
  int src = 25;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000000000000000000000000011001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_int_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_int_to_decimal_2) {
  s21_decimal dst = {0}, origin = {0};
  int src = 0;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_int_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_int_to_decimal_3) {
  s21_decimal dst = {0}, origin = {0};
  int src = -6735;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000000000000000001101001001111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  result_output = s21_from_int_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_int_to_decimal_4) {
  s21_decimal dst = {0}, origin = {0};
  int src = 6735;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000000000000000001101001001111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_int_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_int_to_decimal_5) {
  s21_decimal dst = {0}, origin = {0};
  int src = 9128931;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000000100010110100101111100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_int_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_int_to_decimal_6) {
  s21_decimal dst = {0}, origin = {0};
  int src = -213498348;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00001100101110011011100111101100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  result_output = s21_from_int_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_int_to_decimal_7) {
  s21_decimal dst = {0}, origin = {0};
  int src = 323123;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000000000001001110111000110011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_int_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_int_to_decimal_8) {
  s21_decimal dst = {0}, origin = {0};
  int src = -63908475;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000011110011110010101001111011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  result_output = s21_from_int_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_int_to_decimal_9) {
  s21_decimal dst = {0}, origin = {0};
  int src = 777;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000000000000000000001100001001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_int_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_int_to_decimal_10) {
  s21_decimal dst = {0}, origin = {0};
  int src = 1239345;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000000000100101110100100110001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_int_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_int_to_decimal_11) {
  s21_decimal dst = {0}, origin = {0};
  int src = 843652932;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00110010010010010001111101000100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_int_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_int_to_decimal_12) {
  s21_decimal dst = {0}, origin = {0};
  int src = -290385;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000000000001000110111001010001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  result_output = s21_from_int_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_int_to_decimal_13) {
  s21_decimal dst = {0}, origin = {0};
  int src = -63428750;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000011110001111101100010001110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  result_output = s21_from_int_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_int_to_decimal_14) {
  s21_decimal dst = {0}, origin = {0};
  int src = 931023821;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00110111011111100100101111001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_int_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_int_to_decimal_15) {
  s21_decimal dst = {0}, origin = {0};
  int src = -123901248;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000111011000101001010101000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  result_output = s21_from_int_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_int_to_decimal_16) {
  s21_decimal dst = {0}, origin = {0};
  int src = 9048238;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000000100010100001000010101110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_int_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_int_to_decimal_17) {
  s21_decimal dst = {0}, origin = {0};
  int src = 44812342;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000010101010111100100000110110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_int_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_int_to_decimal_18) {
  s21_decimal dst = {0}, origin = {0};
  int src = 318093809;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00010010111101011011100111110001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_int_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_int_to_decimal_19) {
  s21_decimal dst = {0}, origin = {0};
  int src = INT_MAX;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b01111111111111111111111111111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_int_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_int_to_decimal_20) {
  s21_decimal dst = {0}, origin = {0};
  int src = -INT_MIN;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b10000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  result_output = s21_from_int_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_int_to_decimal_21) {
  s21_decimal dst = {0}, origin = {0};
  int src = 7777777;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000000011101101010110111110001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_int_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_decimal_to_int_1) {
  s21_decimal src = {0};
  int dst = 0;
  int origin = 328;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00000000000000000000000101001000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_int_2) {
  s21_decimal src = {0};
  int dst = 0;
  int origin = -567389;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00000000000010001010100001011101;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_int_3) {
  s21_decimal src = {0};
  int dst = 0;
  int origin = 78914278;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00000100101101000010001011100110;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_int_4) {
  s21_decimal src = {0};
  int dst = 0;
  int origin = -9024152;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00000000100010011011001010011000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_int_6) {
  s21_decimal src = {0};
  int dst = 0;
  int origin = INT_MAX;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b01111111111111111111111111111111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_int_7) {
  s21_decimal src = {0};
  int dst = 0;
  int origin = -INT_MIN;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b10000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_int_8) {
  s21_decimal src = {0};
  int dst = 0;
  int origin = 0;
  int s21_output = 0;
  int origin_output = 1;
  src.bits[0] = 0b00000000000001000001000000000000;
  src.bits[1] = 0b00010000000000111110000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_int_9) {
  s21_decimal src = {0};  // 9024.1522131
  int dst = 0;
  int origin = 9024;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00000010110100000101100111010011;
  src.bits[1] = 0b00000000000000000000000000010101;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001110000000000000000;
  s21_output = s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_int_10) {
  // Тест на ноль
  s21_decimal src = {0};
  int dst = 0;
  int origin = 0;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_int_11) {
  s21_decimal src = {0};
  int dst = 0;
  int origin = 0;
  int s21_output = 0;
  int origin_output = 1;
  src.bits[0] = 0b00100000000111111000000000000000;
  src.bits[1] = 0b00010000100000010000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000100000000000000000;
  s21_output = s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_int_12) {
  s21_decimal src = {0};  // 12691963.90415
  int dst = 0;
  int origin = 12691963;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b10000010000000000000000000001111;
  src.bits[1] = 0b00000000000000000000000100100111;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001010000000000000000;
  s21_output = s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_int_13) {
  s21_decimal src = {0};  // 4835703.280780685256823548
  int dst = 0;
  int origin = -4835703;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00000000000000100001001011111100;
  src.bits[1] = 0b00000000000010000100000000000000;
  src.bits[2] = 0b00000000000001000000000000000000;
  src.bits[3] = 0b10000000000100100000000000000000;
  s21_output = s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_int_14) {
  s21_decimal src = {0};
  int dst = 0;
  int origin = -8648835;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00000000100000111111100010000011;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_int_16) {
  s21_decimal src = {0};  // -483570327.8528885443526656
  int dst = 0;
  int origin = -483570327;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00000000000010000000000000000000;
  src.bits[1] = 0b00000000000000000100000000000000;
  src.bits[2] = 0b00000000000001000000000000000000;
  src.bits[3] = 0b10000000000100000000000000000000;
  s21_output = s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_int_17) {
  s21_decimal src = {0};
  int dst = 0;
  int origin = -176422656;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00001010100000111111111100000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_int_18) {
  s21_decimal src = {0};  // 2306124484190.502912
  int dst = 0;
  int origin = 0;
  int s21_output = 0;
  int origin_output = 1;
  src.bits[0] = 0b00000000000000011000000000000000;
  src.bits[1] = 0b00100000000000010000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001100000000000000000;
  s21_output = s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_int_19) {
  s21_decimal src = {0};  // -5049163892916.336
  int dst = 0;
  int origin = 0;
  int s21_output = 0;
  int origin_output = 1;
  src.bits[0] = 0b0010100010000000000000001110000;
  src.bits[1] = 0b00000000001000111110000001100000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000110000000000000000;
  s21_output = s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_int_21) {
  s21_decimal src = {0};  // -2147483648.398
  int dst = 0;
  int origin = -2147483648;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00000000000000000000000110001110;
  src.bits[1] = 0b00000000000000000000000111110100;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000110000000000000000;
  s21_output = s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_float_1) {
  // null test
  s21_decimal src = {0};
  float dst = 0;
  float origin = 0;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_float_2) {
  s21_decimal src = {0};
  float dst = 0;
  float origin = 34904134189576704.0;
  int s21_output = 0;
  int origin_output = 0;
  // 34904134189576704
  src.bits[0] = 0b00000111100011111111001000000000;
  src.bits[1] = 0b00000000011111000000000100100000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_float_3) {
  s21_decimal src = {0};
  float dst = 0;
  float origin = 4797149878494552330677518384.0;
  int s21_output = 0;
  int origin_output = 0;
  // 4797149878494552330677518384
  src.bits[0] = 0b00000001111110000000000000110000;
  src.bits[1] = 0b00000000000001111100000111001110;
  src.bits[2] = 0b00001111100000000001110000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_float_4) {
  s21_decimal src = {0};  // -393521882706865627597773856
  float dst = 0;
  float origin = -393521882706865627597773856.0;
  int s21_output = 0;
  int origin_output = 0;
  // -393521882706865627597773856
  src.bits[0] = 0b00000000000011100001110000100000;
  src.bits[1] = 0b00000001111100000000001000000000;
  src.bits[2] = 0b00000001010001011000001110000000;
  src.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_float_5) {
  s21_decimal src = {0};
  float dst = 0;
  float origin = -9108633310992923625263104.0;
  int s21_output = 0;
  int origin_output = 0;
  // -9108633310992923625263104
  src.bits[0] = 0b00001111000111000001000000000000;
  src.bits[1] = 0b00000000010011110010010001111000;
  src.bits[2] = 0b00000000000001111000100011010100;
  src.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_float_6) {
  s21_decimal src = {0};
  float dst = 0;
  float origin = 1363063872823827967.09968961;
  int s21_output = 0;
  int origin_output = 0;
  // 1363063872823827967.09968961
  src.bits[0] = 0b00000000000000000011110001000001;
  src.bits[1] = 0b00001111100011100000000000000000;
  src.bits[2] = 0b00000000011100001100000000000000;
  src.bits[3] = 0b00000000000010000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_float_7) {
  s21_decimal src = {0};
  float dst = 0;
  float origin = 5261245167433.773804376204256;
  int s21_output = 0;
  int origin_output = 0;
  // 5261245167433.773804376204256
  src.bits[0] = 0b00000001000100101010001111100000;
  src.bits[1] = 0b00000110100010010000000000000000;
  src.bits[2] = 0b00010001000000000000000000000000;
  src.bits[3] = 0b00000000000011110000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_float_8) {
  s21_decimal src = {0};
  float dst = 0;
  float origin = 56609.69882341710923195780728;
  int s21_output = 0;
  int origin_output = 0;
  // 56609.69882341710923195780728
  src.bits[0] = 0b00101111000111001000111001111000;
  src.bits[1] = 0b00111101100100010000111100001000;
  src.bits[2] = 0b00010010010010101010010100000000;
  src.bits[3] = 0b00000000000101110000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_float_9) {
  s21_decimal src = {0};
  float dst = 0;
  float origin = 4.0708159123947745298861779463;
  int s21_output = 0;
  int origin_output = 0;
  // 4.0708159123947745298861779463
  src.bits[0] = 0b00101010100111111110101000000111;
  src.bits[1] = 0b00000000111001001001001001000000;
  src.bits[2] = 0b10000011100010010000000000000000;
  src.bits[3] = 0b00000000000111000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_float_10) {
  s21_decimal src = {0};
  float dst = 0;
  float origin = 23725169413499.8007108015104;
  int s21_output = 0;
  int origin_output = 0;
  // 23725169413499.8007108015104
  src.bits[0] = 0b00000000000001110001010000000000;
  src.bits[1] = 0b00011100010000000000000000000000;
  src.bits[2] = 0b00000000110001000100000000000000;
  src.bits[3] = 0b00000000000011010000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_float_11) {
  s21_decimal src = {0};
  float dst = 0;
  float origin = -1518959805.3962457861114052012;
  int s21_output = 0;
  int origin_output = 0;
  // -1518959805.3962457861114052012
  src.bits[0] = 0b01110001011100000011110110101100;
  src.bits[1] = 0b01110110111000011110010010111100;
  src.bits[2] = 0b00110001000101001000101010000000;
  src.bits[3] = 0b10000000000100110000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_float_12) {
  s21_decimal src = {0};
  float dst = 0;
  float origin = -1481684277.941851392;
  int s21_output = 0;
  int origin_output = 0;
  // -1481684277.941851392
  src.bits[0] = 0b00100000000000010101010100000000;
  src.bits[1] = 0b00010100100100000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000010010000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_float_13) {
  s21_decimal src = {0};
  float dst = 0;
  float origin = -1128523307299373639;
  int s21_output = 0;
  int origin_output = 0;
  // -1128523307299373639
  src.bits[0] = 0b00000100010101000000001001000111;
  src.bits[1] = 0b00001111101010010101000111111000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_float_14) {
  s21_decimal src = {0};
  float dst = 0;
  float origin = -7003226049228.9212930415302656;
  int s21_output = 0;
  int origin_output = 0;
  // -7003226049228.9212930415302656
  src.bits[0] = 0b00011100100010101001100000000000;
  src.bits[1] = 0b01111101100100111100101000111000;
  src.bits[2] = 0b11100010010010010101010000000000;
  src.bits[3] = 0b10000000000100000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_float_15) {
  s21_decimal src = {0};
  float dst = 0;
  float origin = -1881943803254996.7908496299504;
  int s21_output = 0;
  int origin_output = 0;
  // -1881943803254996.7908496299504
  src.bits[0] = 0b01010101000010010101010111110000;
  src.bits[1] = 0b11111110000010101010100001101000;
  src.bits[2] = 0b00111100110011110001001100000011;
  src.bits[3] = 0b10000000000011010000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_float_16) {
  s21_decimal src = {0};
  float dst = 0;
  float origin = -20665389400527754396439297.4;
  int s21_output = 0;
  int origin_output = 0;
  // -20665389400527754396439297.4
  src.bits[0] = 0b11110000101000001011111000001110;
  src.bits[1] = 0b00001010101010011111000000111000;
  src.bits[2] = 0b00000000101010101111000010101010;
  src.bits[3] = 0b10000000000000010000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_float_17) {
  s21_decimal src = {0};
  float dst = 0;
  float origin = -3300634434855034222975468124.0;
  int s21_output = 0;
  int origin_output = 0;
  // -3300634434855034222975468124
  src.bits[0] = 0b11111111000010010100001001011100;
  src.bits[1] = 0b00111110000101010111000011100010;
  src.bits[2] = 0b00001010101010100011100010000111;
  src.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_float_18) {
  s21_decimal src = {0};
  float dst = 0;
  float origin = 69737472270073788779167306064.0;
  int s21_output = 0;
  int origin_output = 0;
  // 69737472270073788779167306064.0
  src.bits[0] = 0b11111110001001010101000101010000;
  src.bits[1] = 0b11110001011011011100010101010100;
  src.bits[2] = 0b11100001010101010111110000101010;
  src.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_float_19) {
  s21_decimal src = {0};
  float dst = 0;
  float origin = -79228162514264337593543950335.0;
  int s21_output = 0;
  int origin_output = 0;
  // -79228162514264337593543950335.0
  src.bits[0] = 0b11111111111111111111111111111111;
  src.bits[1] = 0b11111111111111111111111111111111;
  src.bits[2] = 0b11111111111111111111111111111111;
  src.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_float_20) {
  s21_decimal src = {0};
  float dst = 0;
  float origin = 79228162514264337593543950335.0;
  int s21_output = 0;
  int origin_output = 0;
  // 79228162514264337593543950335.0
  src.bits[0] = 0b11111111111111111111111111111111;
  src.bits[1] = 0b11111111111111111111111111111111;
  src.bits[2] = 0b11111111111111111111111111111111;
  src.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_decimal_to_float_21) {
  s21_decimal src = {0};
  float dst = 0;
  float origin = 777777.777777;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b11100111101011100111110001110001;
  src.bits[1] = 0b00000000000000000000011100010010;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001110000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dst);
  ck_assert_int_eq(dst, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_1) {
  s21_decimal dst = {0}, origin = {0};
  float src = 1234.5;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000000000000000011000000111001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000010000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_2) {
  s21_decimal dst = {0}, origin = {0};
  float src = 36401984.2348234;
  int dst_output = 0;
  int result_output = 0;
  // 3640198 | 4
  // 3640198 | 0
  // 36401980
  origin.bits[0] = 0b00000010001010110111001101000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_3) {
  s21_decimal dst = {0}, origin = {0};
  float src = 938293.9;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000101100101111011100100010000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000100000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_4) {
  s21_decimal dst = {0}, origin = {0};
  float src = 5.647812;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000011010111011100100110101000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000001110000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_5) {
  s21_decimal dst = {0}, origin = {0};
  float src = 234.56755;
  int dst_output = 0;
  int result_output = 0;
  // 234.5675 | 5
  // 234.5676
  // 2345676 scale = 4
  origin.bits[0] = 0b00000001011001011110101111110100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] =
      0b00000000000001010000000000000000;  // 0b00000000000000010000000000000000
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_6) {
  s21_decimal dst = {0}, origin = {0};
  float src = 192836;
  // 192835.9|6
  // 192836.0|0
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000000000000101111000101000100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_7) {
  s21_decimal dst = {0}, origin = {0};
  // float src = -192836;
  // 3552346|23461234.12353236
  // 3552346|00000000.0
  int dst_output = 1;     // 0;
  int result_output = 0;  // 0;
  result_output = s21_from_float_to_decimal(1.0 / 0.0, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_8) {
  s21_decimal dst = {0}, origin = {0};
  float src = -12513.13452346524;
  // -12513.13 | 452346524
  // -12513.13
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000000101111101110111101101111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000110000000000000000;
  // 0b10000000000000010000000000000000
  // 0b00000000000000010000000000000000
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_9) {
  s21_decimal dst = {0}, origin = {0};
  float src = 999999995;
  // 9999999|95.0
  // 10000000|00.0
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00111011100110101100101000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_10) {
  s21_decimal dst = {0}, origin = {0};
  float src = 9817369871651865108756081237865.0f;
  int dst_output = 1;
  int result_output = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_11) {
  s21_decimal dst = {0}, origin = {0};
  float src = -79228162514264337593543950335.0f;
  int dst_output = 1;
  int result_output = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_12) {
  s21_decimal dst = {0};
  float src = 0.00000000000000000000000000001f;
  int dst_output = 1;
  int result_output = 0;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_13) {
  s21_decimal result = {0}, origin = {0};
  s21_from_float_to_decimal(127.1234, &result);

  origin.bits[0] = 0b00000000000100110110010111000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000001000000000000000000;

  ck_assert_int_eq(result.bits[0], origin.bits[0]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
}
END_TEST

START_TEST(test_s21_float_to_decimal_14) {
  s21_decimal result;
  s21_from_float_to_decimal(22.14836E+03, &result);
  ck_assert_int_eq(result.bits[0], 22148360);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 196608);
}
END_TEST

START_TEST(test_s21_float_to_decimal_15) {
  s21_decimal result;
  s21_from_float_to_decimal(1.02E+09, &result);
  ck_assert_int_eq(result.bits[0], 1020000000);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_float_to_decimal_16) {
  s21_decimal result;
  s21_from_float_to_decimal(-333.2222, &result);
  ck_assert_int_eq(result.bits[0], 3332222);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2147745792);
}
END_TEST

START_TEST(test_s21_float_to_decimal_21) {
  s21_decimal val;
  s21_from_float_to_decimal(0.03F, &val);
  ck_assert_int_eq(val.bits[0], 30000000);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 589824);
  s21_from_float_to_decimal(127.1234F, &val);
  ck_assert_int_eq(val.bits[0], 1271234);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 262144);
}
END_TEST

START_TEST(test_s21_float_to_decimal_22) {
  s21_decimal val;
  s21_from_float_to_decimal(22.14836E+03F, &val);
  ck_assert_int_eq(val.bits[0], 22148360);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 196608);
}
END_TEST

START_TEST(test_s21_float_to_decimal_23) {
  s21_decimal val;
  s21_from_float_to_decimal(1.02E+09F, &val);
  ck_assert_int_eq(val.bits[0], 1020000000);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(test_s21_float_to_decimal_27) {
  s21_decimal val;
  s21_from_float_to_decimal(0.0F, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(test_s21_float_to_decimal_28) {
  // NULL тест
  s21_decimal dst = {0}, origin = {0};
  float src = 1234.56;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000000101111000110000100000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000001000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_29) {
  s21_decimal dst = {0}, origin = {0};
  float src = 36401987394235.2348234;
  // 3640198|7394235.2348234
  // 3640199|0000000.0
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b01111111100000000000000000000000;
  origin.bits[1] = 0b00000000000000000010000100011011;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_30) {
  s21_decimal dst = {0}, origin = {0};
  float src = 938293.9;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000101100101111011100100010000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000100000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_31) {
  s21_decimal dst = {0}, origin = {0};
  float src = 5.647812;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000011010111011100100110101000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000001110000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_32) {
  s21_decimal dst = {0}, origin = {0};
  float src = 234.56755;
  // 234.5675|5
  // 234.5676|0
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000001011001011110101111110100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000001010000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_33) {
  s21_decimal dst = {0}, origin = {0};
  float src = 192835.96;
  // 192835.9|6
  // 192836.0|0
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000001001001100011111010001100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000100000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_34) {
  s21_decimal dst = {0}, origin = {0};
  float src = 355234623461234.12353236;
  // 3552346|23461234.12353236
  // 3552346|00000000.0
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b10000010000000000000000000000000;
  origin.bits[1] = 0b00000000000000010100001100010101;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_35) {
  s21_decimal dst = {0}, origin = {0};
  float src = -125131345451.13452346524;
  // -1251313|45451.13452346524
  // -1251313|00000.0
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00100010011010001100000000000000;
  origin.bits[1] = 0b00000000000000000000000000011101;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_36) {
  s21_decimal dst = {0}, origin = {0};
  float src = 999999995;
  // 9999999|95.0
  // 10000000|00.0
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00111011100110101100101000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_37) {
  s21_decimal dst = {0}, origin = {0};
  float src = -8472009572345.89374658;
  // -8472009|572345.89374658
  // -8472010|000000.0
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b10001011001000000000000000000000;
  origin.bits[1] = 0b00000000000000000000011110110100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_38) {
  s21_decimal dst = {0}, origin = {0};
  float src = 9817369871651865108756081237865.0f;
  int dst_output = 1;
  int result_output = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_39) {
  s21_decimal dst = {0}, origin = {0};
  float src = 0.0000018294106598175618975897216581f;
  // 0.000001829410|6598175618975897216581f
  // 0.000001829411|0f | scale = 12
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000001000101110010010101011010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000011010000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_float_to_decimal_40) {
  s21_decimal dst = {0}, origin = {0};
  float src = -0.0000000123252331235;
  // -0.00000001232523|31235
  // -0.00000001232523|0
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000000101111000001000101110001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000011110000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(test_s21_int_to_decimal_22) {
  s21_decimal result;
  s21_from_int_to_decimal(0, &result);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_int_to_decimal_23) {
  s21_decimal result;
  s21_from_int_to_decimal(-128, &result);
  ck_assert_int_eq(result.bits[0], 128);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], INT_MIN);
}
END_TEST

START_TEST(test_s21_int_to_decimal_24) {
  s21_decimal result;
  s21_from_int_to_decimal(5000, &result);
  ck_assert_int_eq(result.bits[0], 5000);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

// проверка на преобразование числа с плавающей точкой
// степень скэйла = 2 00000000 00000010 00000000 00000000
START_TEST(test_s21_decimal_to_int_22) {
  int number = 0;  // 2147483647
  s21_decimal src = {{314, 0, 0, 0b10000000000000100000000000000000}};
  s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -3);
  ck_assert_int_eq(s21_from_decimal_to_int(src, &number), 0);
}
END_TEST

START_TEST(test_s21_decimal_to_int_24) {
  int number = 0;
  s21_decimal src = {{INT_MAX, 0, 0, 0}};
  s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, INT_MAX);
  ck_assert_int_eq(s21_from_decimal_to_int(src, &number), 0);
}
END_TEST

START_TEST(test_s21_decimal_to_float_22) {
  float number = 0.0;
  s21_decimal src = {{18122, 0, 0, 2147680256}};
  s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -18.122);
}
END_TEST

START_TEST(test_s21_decimal_to_float_23) {
  float number = 0.0;
  s21_decimal src = {{1812, 0, 0, INT_MIN}};
  s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -1812);
}
END_TEST

START_TEST(test_s21_decimal_to_float_24) {
  float number = 0.0;
  s21_decimal src = {{4294967295, 4294967295, 0, 0}};
  s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, 0xFFFFFFFFFFFFFFFF);
}
END_TEST

Suite *irvingsc_test(void) {
  Suite *s = suite_create("\033[45m-=CONVERTERS=-\033[0m");
  TCase *tc = tcase_create("CONVERTERS");

  suite_add_tcase(s, tc);

  // tests_from_int_to_decimal

  tcase_add_test(tc, test_s21_int_to_decimal_1);
  tcase_add_test(tc, test_s21_int_to_decimal_2);
  tcase_add_test(tc, test_s21_int_to_decimal_3);
  tcase_add_test(tc, test_s21_int_to_decimal_4);
  tcase_add_test(tc, test_s21_int_to_decimal_5);
  tcase_add_test(tc, test_s21_int_to_decimal_6);
  tcase_add_test(tc, test_s21_int_to_decimal_7);
  tcase_add_test(tc, test_s21_int_to_decimal_8);
  tcase_add_test(tc, test_s21_int_to_decimal_9);
  tcase_add_test(tc, test_s21_int_to_decimal_10);
  tcase_add_test(tc, test_s21_int_to_decimal_11);
  tcase_add_test(tc, test_s21_int_to_decimal_12);
  tcase_add_test(tc, test_s21_int_to_decimal_13);
  tcase_add_test(tc, test_s21_int_to_decimal_14);
  tcase_add_test(tc, test_s21_int_to_decimal_15);
  tcase_add_test(tc, test_s21_int_to_decimal_16);
  tcase_add_test(tc, test_s21_int_to_decimal_17);
  tcase_add_test(tc, test_s21_int_to_decimal_18);
  tcase_add_test(tc, test_s21_int_to_decimal_19);
  tcase_add_test(tc, test_s21_int_to_decimal_20);
  tcase_add_test(tc, test_s21_int_to_decimal_21);
  tcase_add_test(tc, test_s21_int_to_decimal_22);
  tcase_add_test(tc, test_s21_int_to_decimal_23);
  tcase_add_test(tc, test_s21_int_to_decimal_24);

  // tests_from_float_to_decimal

  tcase_add_test(tc, test_s21_float_to_decimal_1);
  tcase_add_test(tc, test_s21_float_to_decimal_2);
  tcase_add_test(tc, test_s21_float_to_decimal_3);
  tcase_add_test(tc, test_s21_float_to_decimal_4);
  tcase_add_test(tc, test_s21_float_to_decimal_5);
  tcase_add_test(tc, test_s21_float_to_decimal_6);
  tcase_add_test(tc, test_s21_float_to_decimal_7);
  tcase_add_test(tc, test_s21_float_to_decimal_8);
  tcase_add_test(tc, test_s21_float_to_decimal_9);
  tcase_add_test(tc, test_s21_float_to_decimal_10);
  tcase_add_test(tc, test_s21_float_to_decimal_11);
  tcase_add_test(tc, test_s21_float_to_decimal_12);
  tcase_add_test(tc, test_s21_float_to_decimal_13);
  tcase_add_test(tc, test_s21_float_to_decimal_14);
  tcase_add_test(tc, test_s21_float_to_decimal_15);
  tcase_add_test(tc, test_s21_float_to_decimal_16);
  tcase_add_test(tc, test_s21_float_to_decimal_21);
  tcase_add_test(tc, test_s21_float_to_decimal_22);
  tcase_add_test(tc, test_s21_float_to_decimal_23);
  tcase_add_test(tc, test_s21_float_to_decimal_27);
  tcase_add_test(tc, test_s21_float_to_decimal_28);
  tcase_add_test(tc, test_s21_float_to_decimal_29);
  tcase_add_test(tc, test_s21_float_to_decimal_30);
  tcase_add_test(tc, test_s21_float_to_decimal_31);
  tcase_add_test(tc, test_s21_float_to_decimal_32);
  tcase_add_test(tc, test_s21_float_to_decimal_33);
  tcase_add_test(tc, test_s21_float_to_decimal_34);
  tcase_add_test(tc, test_s21_float_to_decimal_35);
  tcase_add_test(tc, test_s21_float_to_decimal_36);
  tcase_add_test(tc, test_s21_float_to_decimal_37);
  tcase_add_test(tc, test_s21_float_to_decimal_38);
  tcase_add_test(tc, test_s21_float_to_decimal_39);
  tcase_add_test(tc, test_s21_float_to_decimal_40);

  // // tests_from_decimal_to_int

  tcase_add_test(tc, test_s21_decimal_to_int_1);
  tcase_add_test(tc, test_s21_decimal_to_int_2);
  tcase_add_test(tc, test_s21_decimal_to_int_3);
  tcase_add_test(tc, test_s21_decimal_to_int_4);
  tcase_add_test(tc, test_s21_decimal_to_int_6);
  tcase_add_test(tc, test_s21_decimal_to_int_7);
  tcase_add_test(tc, test_s21_decimal_to_int_8);
  tcase_add_test(tc, test_s21_decimal_to_int_9);
  tcase_add_test(tc, test_s21_decimal_to_int_10);
  tcase_add_test(tc, test_s21_decimal_to_int_11);
  tcase_add_test(tc, test_s21_decimal_to_int_12);
  tcase_add_test(tc, test_s21_decimal_to_int_13);
  tcase_add_test(tc, test_s21_decimal_to_int_14);
  tcase_add_test(tc, test_s21_decimal_to_int_16);
  tcase_add_test(tc, test_s21_decimal_to_int_17);
  tcase_add_test(tc, test_s21_decimal_to_int_18);
  tcase_add_test(tc, test_s21_decimal_to_int_19);
  tcase_add_test(tc, test_s21_decimal_to_int_21);
  tcase_add_test(tc, test_s21_decimal_to_int_22);
  tcase_add_test(tc, test_s21_decimal_to_int_24);

  // // tests_from_decimal_to_float

  tcase_add_test(tc, test_s21_decimal_to_float_1);
  tcase_add_test(tc, test_s21_decimal_to_float_2);
  tcase_add_test(tc, test_s21_decimal_to_float_3);
  tcase_add_test(tc, test_s21_decimal_to_float_4);
  tcase_add_test(tc, test_s21_decimal_to_float_5);
  tcase_add_test(tc, test_s21_decimal_to_float_6);
  tcase_add_test(tc, test_s21_decimal_to_float_7);
  tcase_add_test(tc, test_s21_decimal_to_float_8);
  tcase_add_test(tc, test_s21_decimal_to_float_9);
  tcase_add_test(tc, test_s21_decimal_to_float_10);
  tcase_add_test(tc, test_s21_decimal_to_float_11);
  tcase_add_test(tc, test_s21_decimal_to_float_12);
  tcase_add_test(tc, test_s21_decimal_to_float_13);
  tcase_add_test(tc, test_s21_decimal_to_float_14);
  tcase_add_test(tc, test_s21_decimal_to_float_15);
  tcase_add_test(tc, test_s21_decimal_to_float_16);
  tcase_add_test(tc, test_s21_decimal_to_float_17);
  tcase_add_test(tc, test_s21_decimal_to_float_18);
  tcase_add_test(tc, test_s21_decimal_to_float_19);
  tcase_add_test(tc, test_s21_decimal_to_float_20);
  tcase_add_test(tc, test_s21_decimal_to_float_21);
  tcase_add_test(tc, test_s21_decimal_to_float_22);
  tcase_add_test(tc, test_s21_decimal_to_float_23);
  tcase_add_test(tc, test_s21_decimal_to_float_24);

  suite_add_tcase(s, tc);
  return s;
}
