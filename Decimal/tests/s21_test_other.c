#include "s21_test_decimal.h"

START_TEST(test_s21_floor_1) {
  s21_decimal v_1 = {{673988, 0, 0, 262144}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_floor(v_1, &result);
  ck_assert_float_eq(result.bits[0], 67);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_floor_2) {
  s21_decimal v_1 = {{679988, 0, 0, 262144}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_floor(v_1, &result);
  ck_assert_float_eq(result.bits[0], 67);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_floor_3) {
  s21_decimal v_1 = {{679988, 0, 0, 2147745796}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_floor(v_1, &result);
  ck_assert_float_eq(result.bits[0], 68);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(test_s21_floor_4) {
  s21_decimal v_1 = {{2555, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_floor(v_1, &result);
  ck_assert_float_eq(result.bits[0], 2555);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_floor_6) {
  // null test
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00000000000000000000000000000000;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000000000000000000000;
  //
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_8) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // -330034358.000060563
  value.bits[0] = 0b00000000010001001000100010010011;
  value.bits[1] = 0b00000100100101001000010010000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000010010000000000000000;
  // -330034359
  origin.bits[0] = 0b00010011101010111110110010110111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_10) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // -25332308.1000455680
  value.bits[0] = 0b00000000011100001000111000000000;
  value.bits[1] = 0b00000011100000111111110000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000010100000000000000000;
  // -25332309
  origin.bits[0] = 0b00000001100000101000101001010101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_11) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // 0.00000000003452810109649558
  value.bits[0] = 0b00000000000100000000001010010110;
  value.bits[1] = 0b00000000000011000100010001010000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000110100000000000000000;
  // 0
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_12) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // -0.000000000004959928320
  value.bits[0] = 0b00100111101000101000000000000000;
  value.bits[1] = 0b00000000000000000000000000000001;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000101010000000000000000;
  // -1
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_13) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // 27149251.7085128960
  value.bits[0] = 0b10000000000010010010100100000000;
  value.bits[1] = 0b00000011110001001000100100000001;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000010100000000000000000;
  // 27149251
  origin.bits[0] = 0b00000001100111100100001111000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_14) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // 9904296572294616.931377348608
  value.bits[0] = 0b11100000000000000000000000000000;
  value.bits[1] = 0b00000111111110000000000000000001;
  value.bits[2] = 0b00100000000000001010010001100001;
  value.bits[3] = 0b00000000000011000000000000000000;
  // 9904296572294616
  origin.bits[0] = 0b10111110111100010001010111011000;
  origin.bits[1] = 0b00000000001000110010111111100111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_15) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // 22337854.19752363009
  value.bits[0] = 0b00010000110010010101010000000001;
  value.bits[1] = 0b00011111000000000000000000000001;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000010110000000000000000;
  // 22337854
  origin.bits[0] = 0b00000001010101001101100100111110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_16) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  //  -8196555174.425465492
  value.bits[0] = 0b00000001100001010001001010010100;
  value.bits[1] = 0b01110001110000000000001110000001;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000010010000000000000000;
  // -8196555175
  origin.bits[0] = 0b11101000100011011000000110100111;
  origin.bits[1] = 0b00000000000000000000000000000001;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_17) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // 7777777.7777777
  value.bits[0] = 0b00001100110100001101110001110001;
  value.bits[1] = 0b00000000000000000100011010111101;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000001110000000000000000;
  // 7777777
  origin.bits[0] = 0b00000000011101101010110111110001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_18) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // 1080921880.458340136
  value.bits[0] = 0b00101010101010101010011100101000;
  value.bits[1] = 0b00001111000000000011010010111001;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000010010000000000000000;
  // 1080921880
  origin.bits[0] = 0b01000000011011011000111100011000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_19) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // -3.1957442962838464
  value.bits[0] = 0b00000011101110101101001111000000;
  value.bits[1] = 0b00000000011100011000100100100000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000100000000000000000000;
  // -4
  origin.bits[0] = 0b00000000000000000000000000000100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_20) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // -1.28502129019350168
  value.bits[0] = 0b01101001000101000110110010011000;
  value.bits[1] = 0b00000001110010001000100000000001;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000100010000000000000000;
  // -2
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_21) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // 1089644363795118168909.145790
  value.bits[0] = 0b01010010100101011110011010111110;
  value.bits[1] = 0b01010010101110101100100100011111;
  value.bits[2] = 0b00000011100001010101010100101011;
  value.bits[3] = 0b00000000000001100000000000000000;
  // 1089644363795118168909
  origin.bits[0] = 0b00111010100010000001101101001101;
  origin.bits[1] = 0b00010001110110100110111110110000;
  origin.bits[2] = 0b00000000000000000000000000111011;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_23) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // 26745264258900957313380.20864
  value.bits[0] = 0b00001110010000101000100000000000;
  value.bits[1] = 0b00010000111001010010100001000110;
  value.bits[2] = 0b00001000101001000101000100000000;
  value.bits[3] = 0b00000000000001010000000000000000;
  // 26745264258900957313380
  origin.bits[0] = 0b10111110100011111011100101100100;
  origin.bits[1] = 0b11011101000110100010110011111100;
  origin.bits[2] = 0b00000000000000000000010110101001;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_floor_24) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // 1551543454561865943408.9728595
  value.bits[0] = 0b10000000000000001100101001010011;
  value.bits[1] = 0b00010010001000010011111100000001;
  value.bits[2] = 0b00110010001000100001000100010000;
  value.bits[3] = 0b00000000000001110000000000000000;
  // 1551543454561865943408
  origin.bits[0] = 0b10010110011100011100100101110000;
  origin.bits[1] = 0b00011011111111011010011101111110;
  origin.bits[2] = 0b00000000000000000000000001010100;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_floor(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_1) {
  s21_decimal v_1 = {{5, 0, 1, 0}};
  // put_scale(&v_1, 2);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(v_1, &result);
  ck_assert_float_eq(result.bits[0], 5);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 1);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_round_2) {
  s21_decimal v_1 = {{155, 1, 1, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(v_1, &result);
  ck_assert_float_eq(result.bits[0], 155);
  ck_assert_float_eq(result.bits[1], 1);
  ck_assert_float_eq(result.bits[2], 1);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_round_3) {
  s21_decimal v_1 = {{155, 1, 1, 2147483648}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(v_1, &result);
  ck_assert_float_eq(result.bits[0], 155);
  ck_assert_float_eq(result.bits[1], 1);
  ck_assert_float_eq(result.bits[2], 1);
  ck_assert_float_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(test_round_4) {
  s21_decimal v_1 = {{0, 1, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(v_1, &result);
  ck_assert_float_eq(result.bits[0], 0);
  ck_assert_float_eq(result.bits[1], 1);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_round_6) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // 18446744073709551615
  // 349738609805692.312931738872
  value.bits[0] = 0b01001001101100110010010011111000;
  value.bits[1] = 0b00000111000101010101101010100101;
  value.bits[2] = 0b00000001001000010100110000001000;
  value.bits[3] = 0b00000000000011000000000000000000;
  // 349738609805692
  // 349738609805693
  //  11011101100110100000100101111101
  origin.bits[0] = 0b11011101100110100000100101111100;
  origin.bits[1] = 0b00000000000000010011111000010101;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  // ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_7) {
  // null
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00000000000000000000000000000000;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000000000000000000000;
  //
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_8) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // 330121751632009242242.714390
  value.bits[0] = 0b01111100101000000000101100010110;
  value.bits[1] = 0b00000011111001001001111011101110;
  value.bits[2] = 0b00000001000100010001001000000000;
  value.bits[3] = 0b00000000000001100000000000000000;
  // 330121751632009242243
  origin.bits[0] = 0b10011111101001000010011010000011;
  origin.bits[1] = 0b11100101010111000001000000001100;
  origin.bits[2] = 0b00000000000000000000000000010001;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_9) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // 4247984203.5
  value.bits[0] = 0b11100011111111101111001011110011;
  value.bits[1] = 0b00000000000000000000000000001001;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000010000000000000000;
  // 4247984204
  origin.bits[0] = 0b11111101001100110001100001001100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_11) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // 7895075245720457.50000001
  value.bits[0] = 0b10110100001100110101100110000001;
  value.bits[1] = 0b01001001111001100001000000100010;
  value.bits[2] = 0b00000000000000001010011100101111;
  value.bits[3] = 0b00000000000010000000000000000000;
  // 7895075245720458
  origin.bits[0] = 0b01110011011111110000001110001010;
  origin.bits[1] = 0b00000000000111000000110010000111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_12) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // 89057937594.5000000001
  value.bits[0] = 0b00100010110010011001101000000001;
  value.bits[1] = 0b01000111010001011000011111101110;
  value.bits[2] = 0b00000000000000000000000000110000;
  value.bits[3] = 0b00000000000010100000000000000000;
  // 89057937595
  origin.bits[0] = 0b10111100010001000100100010111011;
  origin.bits[1] = 0b00000000000000000000000000010100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_14) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // 641978563.5000000000
  value.bits[0] = 0b10000100010101001001111000000000;
  value.bits[1] = 0b01011001000101111010100100000101;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000010100000000000000000;
  // 641978564
  origin.bits[0] = 0b00100110010000111101000011000100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_15) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // 0.465
  value.bits[0] = 0b00000000000000000000000111010001;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000110000000000000000;
  // 0
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_16) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // -908745357.386764378
  value.bits[0] = 0b01111010010100101101000001011010;
  value.bits[1] = 0b00001100100111001000001100010110;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000010010000000000000000;
  // -908745357
  origin.bits[0] = 0b00110110001010100101101010001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_17) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // -832381902.74234
  value.bits[0] = 0b01100110110000110101011010111010;
  value.bits[1] = 0b00000000000000000100101110110100;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000001010000000000000000;
  // -832381903
  origin.bits[0] = 0b00110001100111010010001111001111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_20) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // -758932283451.50000001
  value.bits[0] = 0b10010010010001011100101110000001;
  value.bits[1] = 0b00011101001110101110100100010100;
  value.bits[2] = 0b00000000000000000000000000000100;
  value.bits[3] = 0b10000000000010000000000000000000;
  // -758932283452
  origin.bits[0] = 0b10110011111000111010000000111100;
  origin.bits[1] = 0b00000000000000000000000010110000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_21) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // -572895792658.5000000000001
  value.bits[0] = 0b11110000000010001001000000000001;
  value.bits[1] = 0b01101110011101110000110100010011;
  value.bits[2] = 0b00000000000001001011110100100111;
  value.bits[3] = 0b10000000000011010000000000000000;
  // -572895792659
  origin.bits[0] = 0b01100011010000000000111000010011;
  origin.bits[1] = 0b00000000000000000000000010000101;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_24) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // -99999941234.7154351345
  value.bits[0] = 0b01000111100000100100010011110001;
  value.bits[1] = 0b00110101110001111001011101001110;
  value.bits[2] = 0b00000000000000000000000000110110;
  value.bits[3] = 0b10000000000010100000000000000000;
  // -99999941235
  origin.bits[0] = 0b01001000011101100000001001110011;
  origin.bits[1] = 0b00000000000000000000000000010111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_round_25) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // -213521353245.3125
  value.bits[0] = 0b00100100000111110001100100000101;
  value.bits[1] = 0b00000000000001111001010111110111;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000001000000000000000000;
  // -213521353245
  // 10110110110111010100101000011101
  origin.bits[0] = 0b10110110110111010100101000011101;
  origin.bits[1] = 0b00000000000000000000000000110001;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_round(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_negate_1) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00000110100010010001001110000000;
  value.bits[1] = 0b01100000000000001100101100000000;
  value.bits[2] = 0b00001000100100010000000010000000;
  value.bits[3] = 0b00000000000000000000000000000000;
  //
  origin.bits[0] = 0b00000110100010010001001110000000;
  origin.bits[1] = 0b01100000000000001100101100000000;
  origin.bits[2] = 0b00001000100100010000000010000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_negate_2) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00010001000100011100000001100001;
  value.bits[1] = 0b10010001000100111001001101100011;
  value.bits[2] = 0b00010001011001100110001111011110;
  value.bits[3] = 0b00000000000000000000000000000000;
  //
  origin.bits[0] = 0b00010001000100011100000001100001;
  origin.bits[1] = 0b10010001000100111001001101100011;
  origin.bits[2] = 0b00010001011001100110001111011110;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_negate_3) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b01100101010010101010101010100000;
  value.bits[1] = 0b00010001101110100101011111100001;
  value.bits[2] = 0b00001100100010010010101011100000;
  value.bits[3] = 0b10000000000000000000000000000000;
  //
  origin.bits[0] = 0b01100101010010101010101010100000;
  origin.bits[1] = 0b00010001101110100101011111100001;
  origin.bits[2] = 0b00001100100010010010101011100000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_negate_4) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00000000101101011001000101011011;
  value.bits[1] = 0b00100101010001011011011100010010;
  value.bits[2] = 0b01001001010010100001111001110000;
  value.bits[3] = 0b10000000000000000000000000000000;
  //
  origin.bits[0] = 0b00000000101101011001000101011011;
  origin.bits[1] = 0b00100101010001011011011100010010;
  origin.bits[2] = 0b01001001010010100001111001110000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_negate_5) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b01110010100010010010101010111100;
  value.bits[1] = 0b01110000101001000101101001010111;
  value.bits[2] = 0b00011001000101000100010011001110;
  value.bits[3] = 0b00000000000001110000000000000000;
  //
  origin.bits[0] = 0b01110010100010010010101010111100;
  origin.bits[1] = 0b01110000101001000101101001010111;
  origin.bits[2] = 0b00011001000101000100010011001110;
  origin.bits[3] = 0b10000000000001110000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_negate_6) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00110010110000001010000100010110;
  value.bits[1] = 0b01101001010110101011100000001111;
  value.bits[2] = 0b01001001000010010011110010100011;
  value.bits[3] = 0b00000000000100100000000000000000;
  //
  origin.bits[0] = 0b00110010110000001010000100010110;
  origin.bits[1] = 0b01101001010110101011100000001111;
  origin.bits[2] = 0b01001001000010010011110010100011;
  origin.bits[3] = 0b10000000000100100000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_negate_7) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00010010010111110000111011001110;
  value.bits[1] = 0b01111100000111000110010011001000;
  value.bits[2] = 0b00010010010010000110000011100000;
  value.bits[3] = 0b10000000000110010000000000000000;
  //
  origin.bits[0] = 0b00010010010111110000111011001110;
  origin.bits[1] = 0b01111100000111000110010011001000;
  origin.bits[2] = 0b00010010010010000110000011100000;
  origin.bits[3] = 0b00000000000110010000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_negate_8) {
  // null
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00000000000000000000000000000000;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000000000000000000000;
  //
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_negate_9) {
  // negate null
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00000000000000000000000000000000;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000000000000000000000000;
  //
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_negate_10) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00000000000110010010000100000000;
  value.bits[1] = 0b00010000000100010001010100000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000011110000000000000000;
  //
  origin.bits[0] = 0b00000000000110010010000100000000;
  origin.bits[1] = 0b00010000000100010001010100000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000011110000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_negate_11) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00110001000110010010000100000000;
  value.bits[1] = 0b00010000000100010001010100000000;
  value.bits[2] = 0b00001111100100010000100000000000;
  value.bits[3] = 0b00000000000110100000000000000000;
  //
  origin.bits[0] = 0b00110001000110010010000100000000;
  origin.bits[1] = 0b00010000000100010001010100000000;
  origin.bits[2] = 0b00001111100100010000100000000000;
  origin.bits[3] = 0b10000000000110100000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_negate_12) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  //
  value.bits[0] = 0b00110001000110010010000100000000;
  value.bits[1] = 0b00010000000100010001010100000000;
  value.bits[2] = 0b00001111100100010000100000000000;
  value.bits[3] = 0b00000000000110100000000000000000;
  //
  origin.bits[0] = 0b00110001000110010010000100000000;
  origin.bits[1] = 0b00010000000100010001010100000000;
  origin.bits[2] = 0b00001111100100010000100000000000;
  origin.bits[3] = 0b10000000000110100000000000000000;
  s21_output = s21_negate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST
START_TEST(test_s21_negate_13) {
  s21_decimal v_1 = {{155, 1, 1, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_negate(v_1, &result);
  ck_assert_float_eq(result.bits[0], 155);
  ck_assert_float_eq(result.bits[1], 1);
  ck_assert_float_eq(result.bits[2], 1);
  ck_assert_float_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(test_s21_negate_14) {
  s21_decimal v_1 = {{155, 1, 1, 2147483648}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_negate(v_1, &result);
  ck_assert_float_eq(result.bits[0], 155);
  ck_assert_float_eq(result.bits[1], 1);
  ck_assert_float_eq(result.bits[2], 1);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_truncate_1) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // 264107318112051817.4866968866
  value.bits[0] = 0b00000000010000001001000100100010;
  value.bits[1] = 0b00001000100000000000010010010000;
  value.bits[2] = 0b00001000100010001010010100000000;
  value.bits[3] = 0b00000000000010100000000000000000;
  // 264107318112051817
  origin.bits[0] = 0b11011110101001100110001001101001;
  origin.bits[1] = 0b00000011101010100100110000110100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_truncate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_truncate_2) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // 975909603428014204144180.7086
  value.bits[0] = 0b00001001000100101010101011101110;
  value.bits[1] = 0b00010111110100101100100001110000;
  value.bits[2] = 0b00011111100010001000100011111000;
  value.bits[3] = 0b00000000000001000000000000000000;
  // 975909603428014204144180
  origin.bits[0] = 0b00110011100111000100101000110100;
  origin.bits[1] = 0b00101010011001010101111100011001;
  origin.bits[2] = 0b00000000000000001100111010101000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_truncate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_truncate_3) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // 35127093725958791885374.000000
  value.bits[0] = 0b01010010100100101000101110000000;
  value.bits[1] = 0b10001010000100010000111000000101;
  value.bits[2] = 0b01110001100000000111001101101110;
  value.bits[3] = 0b00000000000001100000000000000000;
  // 35127093725958791885374
  origin.bits[0] = 0b11001010100000011111001000111110;
  origin.bits[1] = 0b00111110010110100110000001110000;
  origin.bits[2] = 0b00000000000000000000011101110000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_truncate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_truncate_4) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // 11301643024.744584584724317966
  value.bits[0] = 0b00111111111110011000011100001110;
  value.bits[1] = 0b00000001000100100101101010010110;
  value.bits[2] = 0b00100100100001001000000000000000;
  value.bits[3] = 0b00000000000100100000000000000000;
  // 11301643024
  origin.bits[0] = 0b10100001101000010110001100010000;
  origin.bits[1] = 0b00000000000000000000000000000010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_truncate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_truncate_5) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // 5947153396147561.664
  value.bits[0] = 0b00100010001000100010010011000000;
  value.bits[1] = 0b01010010100010001000100010000001;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000110000000000000000;
  // 5947153396147561
  origin.bits[0] = 0b10001101100110100010010101101001;
  origin.bits[1] = 0b00000000000101010010000011100111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_truncate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_truncate_6) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // -919639.1385315400060
  value.bits[0] = 0b10001001001011111101100101111100;
  value.bits[1] = 0b01111111101000000010010100111101;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000011010000000000000000;
  // -919639
  origin.bits[0] = 0b00000000000011100000100001010111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_truncate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_truncate_7) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // -9876.540164283795735
  value.bits[0] = 0b10000110000000111000100100010111;
  value.bits[1] = 0b10001001000100001000010011110011;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000011110000000000000000;
  // -9876
  origin.bits[0] = 0b00000000000000000010011010010100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_truncate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_truncate_8) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // -3031287.3475492500523254791
  value.bits[0] = 0b11111000000100010000010000000111;
  value.bits[1] = 0b00101001111100000010000110001110;
  value.bits[2] = 0b00000000000110010001001100000000;
  value.bits[3] = 0b10000000000100110000000000000000;
  // -3031287
  origin.bits[0] = 0b00000000001011100100000011110111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_truncate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_truncate_10) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // 7777777.7777777
  value.bits[0] = 0b00001100110100001101110001110001;
  value.bits[1] = 0b00000000000000000100011010111101;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000001110000000000000000;
  // 7777777
  origin.bits[0] = 0b00000000011101101010110111110001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_truncate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

START_TEST(test_s21_truncate_11) {
  s21_decimal v_1 = {{673988, 0, 0, 262144}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(v_1, &result);
  ck_assert_float_eq(result.bits[0], 67);
  ck_assert_float_eq(result.bits[1], 0);
  ck_assert_float_eq(result.bits[2], 0);
  ck_assert_float_eq(result.bits[3], 0);
}
END_TEST

START_TEST(test_s21_truncate_12) {
  s21_decimal v_1 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(-2744406, &v_1);

  s21_truncate(v_1, &result);

  ck_assert_int_eq(result.bits[0], 2744406);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(test_s21_truncate_13) {
  s21_decimal value = {0}, result = {0}, origin = {0};
  int s21_output = 0;
  int origin_output = 0;
  // -3.1957442962838464
  value.bits[0] = 0b00000011101110101101001111000000;
  value.bits[1] = 0b00000000011100011000100100100000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000100000000000000000000;
  // 3
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;

  s21_output = s21_truncate(value, &result);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin_output, s21_output);
}
END_TEST

Suite *luannkla_test(void) {
  Suite *s = suite_create("\033[45m-=OTHER=-\033[0m");
  TCase *tc1_1 = tcase_create("s21_decimal: ");

  suite_add_tcase(s, tc1_1);
  //    test_s21_floor
  tcase_add_test(tc1_1, test_s21_floor_1);
  tcase_add_test(tc1_1, test_s21_floor_2);
  tcase_add_test(tc1_1, test_s21_floor_3);
  tcase_add_test(tc1_1, test_s21_floor_4);
  tcase_add_test(tc1_1, test_s21_floor_6);
  tcase_add_test(tc1_1, test_s21_floor_8);
  tcase_add_test(tc1_1, test_s21_floor_10);
  tcase_add_test(tc1_1, test_s21_floor_11);
  tcase_add_test(tc1_1, test_s21_floor_12);
  tcase_add_test(tc1_1, test_s21_floor_13);
  tcase_add_test(tc1_1, test_s21_floor_14);
  tcase_add_test(tc1_1, test_s21_floor_15);
  tcase_add_test(tc1_1, test_s21_floor_16);
  tcase_add_test(tc1_1, test_s21_floor_17);
  tcase_add_test(tc1_1, test_s21_floor_18);
  tcase_add_test(tc1_1, test_s21_floor_19);
  tcase_add_test(tc1_1, test_s21_floor_20);
  tcase_add_test(tc1_1, test_s21_floor_21);
  tcase_add_test(tc1_1, test_s21_floor_23);
  tcase_add_test(tc1_1, test_s21_floor_24);
  //  tests_round
  tcase_add_test(tc1_1, test_round_1);
  tcase_add_test(tc1_1, test_round_2);
  tcase_add_test(tc1_1, test_round_3);
  tcase_add_test(tc1_1, test_round_4);
  tcase_add_test(tc1_1, test_round_6);
  tcase_add_test(tc1_1, test_round_7);
  tcase_add_test(tc1_1, test_round_8);
  tcase_add_test(tc1_1, test_round_9);
  tcase_add_test(tc1_1, test_round_11);
  tcase_add_test(tc1_1, test_round_12);
  tcase_add_test(tc1_1, test_round_14);
  tcase_add_test(tc1_1, test_round_15);
  tcase_add_test(tc1_1, test_round_16);
  tcase_add_test(tc1_1, test_round_17);
  tcase_add_test(tc1_1, test_round_20);
  tcase_add_test(tc1_1, test_round_21);
  tcase_add_test(tc1_1, test_round_24);
  tcase_add_test(tc1_1, test_round_25);

  //  tests_negate
  tcase_add_test(tc1_1, test_s21_negate_1);
  tcase_add_test(tc1_1, test_s21_negate_2);
  tcase_add_test(tc1_1, test_s21_negate_3);
  tcase_add_test(tc1_1, test_s21_negate_4);
  tcase_add_test(tc1_1, test_s21_negate_5);
  tcase_add_test(tc1_1, test_s21_negate_6);
  tcase_add_test(tc1_1, test_s21_negate_7);
  tcase_add_test(tc1_1, test_s21_negate_8);
  tcase_add_test(tc1_1, test_s21_negate_9);
  tcase_add_test(tc1_1, test_s21_negate_10);
  tcase_add_test(tc1_1, test_s21_negate_11);
  tcase_add_test(tc1_1, test_s21_negate_12);
  tcase_add_test(tc1_1, test_s21_negate_13);
  tcase_add_test(tc1_1, test_s21_negate_14);

  //    tests_truncate
  tcase_add_test(tc1_1, test_s21_truncate_1);
  tcase_add_test(tc1_1, test_s21_truncate_2);
  tcase_add_test(tc1_1, test_s21_truncate_3);
  tcase_add_test(tc1_1, test_s21_truncate_4);
  tcase_add_test(tc1_1, test_s21_truncate_5);
  tcase_add_test(tc1_1, test_s21_truncate_6);
  tcase_add_test(tc1_1, test_s21_truncate_7);
  tcase_add_test(tc1_1, test_s21_truncate_8);
  tcase_add_test(tc1_1, test_s21_truncate_10);
  tcase_add_test(tc1_1, test_s21_truncate_11);
  tcase_add_test(tc1_1, test_s21_truncate_12);
  tcase_add_test(tc1_1, test_s21_truncate_13);
  return s;
}