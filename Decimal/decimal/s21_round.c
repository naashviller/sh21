#include "../s21_decimal.h"
#include "s21_help_function.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int flag = result ? 0 : 1;
  if (!flag) {
    s21_truncate(value, result);
    if (s21_is_negative(value) && !s21_is_equal(value, *result)) {
      s21_decimal one = {{1u, 0u, 0u, 0x80000000u}};
      s21_add(*result, one, result);
    }
  }
  return flag;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int flag = result ? 0 : 1;
  if (!flag) {
    s21_decimal addition = {{5u, 0u, 0u, 0x00010000u}};
    s21_add(value, addition, result);
    s21_floor(*result, result);
  }
  return flag;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int flag = result ? 0 : 1;
  if (!flag) {
    int sign = s21_is_negative(value);
    int scale = s21_get_scale(value);
    s21_decimal base = {0};
    s21_copy_all_bytes(value, result);
    s21_from_int_to_decimal(10, &base);
    if (sign) {
      s21_set_plus(result);
    }
    if (s21_is_less(*result, base)) {
      s21_support_truncate(value, result);
    } else {
      while (scale != 0) {
        s21_support_div(*result, base, result);
        scale--;
      }
      if (sign) {
        s21_set_minus(result);
      } else {
        s21_set_plus(result);
      }
    }
  }
  return flag;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  int flag = result ? 0 : 1;
  if (!flag) {
    s21_copy_all_bytes(value, result);
    if (s21_is_negative(*result))
      s21_set_plus(result);
    else
      s21_set_minus(result);
  }
  return flag;
}
