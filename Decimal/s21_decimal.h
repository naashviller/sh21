#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0   // OK
#define INF 1  // число слишком велико или равно бесконечности
#define NEG_INF 2  // число слишком мало или равно отрицательной бесконечности
#define s21_NAN 3  // 3 - деление на 0
#define TRUE 1
#define FALSE 0
#define ERROR 1
#define FLOAT_ROUND 7
#define S21_MAXFLOAT 3.402823466e38
#define MAX_DECIMAL "79228162514264337593543950335"
#define MAXEXP 28
#define MAXDEC 29
#define MAX_STRING 100
#define ZERO 0b00000000000000000000000000000000  // 0x80000000
#define S21_INFINITY (1.0 / 0.0)
#define S21_NAN (0.0 / 0.0)
#define INT_MAX 2147483647U
#define INT_MIN 2147483648U
#define UINT_MAX 4294967295U
#define DECIMAL_MAX 79228162514264337593543950335
#define SCALE 0x00ff0000
#define MINUS 0x80000000

typedef struct {
  unsigned int bits[4];
} s21_decimal;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_support_add(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result);
int s21_error_add(s21_decimal value_1, s21_decimal value_2);
int s21_root_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
                 bool sign_1, bool sign_2);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void s21_support_sub(s21_decimal value_1, s21_decimal value_2,
                     s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_fractional_division(s21_decimal value_1, s21_decimal value_2,
                            s21_decimal *result);
s21_decimal s21_support_div(s21_decimal value_1, s21_decimal value_2,
                            s21_decimal *result);
int s21_remainder_division(s21_decimal value_1, s21_decimal value_2,
                           s21_decimal *result);

int s21_is_less(s21_decimal num1, s21_decimal num2);
int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_greater(s21_decimal num1, s21_decimal num2);
int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_equal(s21_decimal num1, s21_decimal num2);
int s21_is_not_equal(s21_decimal num1, s21_decimal num2);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

#endif
