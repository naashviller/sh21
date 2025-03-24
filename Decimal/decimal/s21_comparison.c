#include "../s21_decimal.h"
#include "s21_help_function.h"

int s21_is_less(s21_decimal num, s21_decimal num1) {
  int flag = 0, flag_ex = 0;
  int result = 0;
  int sign_num1 = s21_is_negative(num);
  int sign_num2 = s21_is_negative(num1);
  int scale_num1 = s21_get_scale(num);
  int scale_num2 = s21_get_scale(num1);

  if (num.bits[0] == 0 && num1.bits[0] == 0 && num.bits[1] == 0 &&
      num1.bits[1] == 0 && num.bits[2] == 0 && num1.bits[2] == 0 &&
      scale_num1 == 0 && scale_num2 == 0) {
    if (sign_num1 == 1 || sign_num2 == 1) {
      result = 0;
      flag_ex = 1;
    }
  }
  if (sign_num1 == sign_num2 && !flag_ex) {
    int scale_diff = scale_num1 - scale_num2;
    if (scale_diff != 0) {
      s21_normalize_scale(&num, &num1);
    }
    for (int i = 2; i >= 0 && !result && !flag; i--) {
      if (num.bits[i] < num1.bits[i]) {
        if (sign_num1 == 0)
          result = 1;
        else
          flag = 1;
      } else if (num.bits[i] > num1.bits[i]) {
        if (sign_num1 == 1)
          result = 1;
        else
          flag = 1;
      }
    }
  } else if (sign_num1 == 1 && !flag_ex) {
    result = 1;
  }

  return result;
}

int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2) {
  return s21_is_less(num1, num2) == 1 || s21_is_equal(num1, num2) == 1;
}

int s21_is_greater(s21_decimal num, s21_decimal num1) {
  int result = 0, flag = 0, flag_ex = 0;
  int sign_num1 = s21_is_negative(num);
  int sign_num2 = s21_is_negative(num1);
  int scale_num1 = s21_get_scale(num);
  int scale_num2 = s21_get_scale(num1);

  if (num.bits[0] == 0 && num1.bits[0] == 0 && num.bits[1] == 0 &&
      num1.bits[1] == 0 && num.bits[2] == 0 && num1.bits[2] == 0 &&
      scale_num1 == 0 && scale_num2 == 0) {
    if (sign_num1 == 1 || sign_num2 == 1) {
      result = 0;
      flag_ex = 1;
    }
  }
  if (sign_num1 == sign_num2 && !flag_ex) {
    int scale_diff = scale_num1 - scale_num2;
    if (scale_diff != 0) {
      s21_normalize_scale(&num, &num1);
    }
    for (int i = 2; i >= 0 && !result && !flag; i--) {
      if (num.bits[i] > num1.bits[i]) {
        if (sign_num1 == 0)
          result = 1;
        else
          flag = 1;
      } else if (num.bits[i] < num1.bits[i]) {
        if (sign_num1 == 1)
          result = 1;
        else
          flag = 1;
      }
    }
  } else if (sign_num1 == 0 && !flag_ex) {
    result = 1;
  }

  return result;
}

int s21_is_greater_or_equal(s21_decimal num, s21_decimal num1) {
  return s21_is_greater(num, num1) || s21_is_equal(num, num1);
}

int s21_is_equal(s21_decimal num, s21_decimal num1) {
  int result = 0, flag = 0;
  int sign = s21_is_negative(num);
  int sign1 = s21_is_negative(num1);
  int scale_num1 = s21_get_scale(num);
  int scale_num2 = s21_get_scale(num1);

  if (num.bits[0] == 0 && num1.bits[0] == 0 && num.bits[1] == 0 &&
      num1.bits[1] == 0 && num.bits[2] == 0 && num1.bits[2] == 0 &&
      scale_num1 == 0 && scale_num2 == 0) {
    if (sign == 1 || sign1 == 1) {
      result = 1;
    }
  }
  int scale_diff = scale_num1 - scale_num2;
  if (sign == sign1) {
    if (scale_diff != 0) {
      s21_normalize_scale(&num, &num1);
    }
    for (int i = 2; i >= 0 && !flag; i--) {
      if (num.bits[i] == num1.bits[i]) {
        result = 1;
      } else {
        result = 0;
        flag = 1;
      }
    }
  }

  return result;
}

int s21_is_not_equal(s21_decimal num1, s21_decimal num2) {
  return !s21_is_equal(num1, num2);
}
