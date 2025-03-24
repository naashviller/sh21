#include "../s21_decimal.h"
#include "s21_help_function.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0;
  s21_decimal tmp_1 = {0};
  s21_decimal tmp_2 = {0};
  int scale_1 = s21_get_scale(value_1);
  int scale_2 = s21_get_scale(value_2);
  bool sign_1 = s21_is_negative(value_1);
  bool sign_2 = s21_is_negative(value_2);

  s21_init_value(result);
  if (scale_1 == 255 || scale_2 == 255) {
    if (sign_1) {
      error = 2;
    } else {
      error = 1;
    }
  } else {
    if (s21_is_null(value_1)) {
      *result = value_2;
    } else if (s21_is_null(value_2)) {
      *result = value_1;
    } else {
      s21_copy_all_bytes(value_1, &tmp_1);
      s21_copy_all_bytes(value_2, &tmp_2);
      s21_set_plus(&tmp_1);
      s21_set_plus(&tmp_2);
      if (scale_1 != scale_2) {
        error = s21_normalize_scale(&tmp_1, &tmp_2);
      }
      if (error) {
        s21_error_add(value_1, value_2);
      } else {
        error = s21_root_add(tmp_1, tmp_2, result, sign_1, sign_2);
        int scale_res = s21_get_scale(tmp_1);
        s21_set_scale(result, scale_res);
        if (error && s21_is_negative(*result)) {
          error = 2;
        } else if (error && !s21_is_negative(*result)) {
          error = 1;
        }
      }
    }
  }

  return error;
}

int s21_support_add(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result) {
  int overflow = 0;

  s21_init_value(result);
  for (int i = 0; i <= 95; i++) {
    int first_bit = s21_get_bit(value_1, i);
    int second_bit = s21_get_bit(value_2, i);
    int res_bit = first_bit + second_bit + overflow;
    overflow = res_bit / 2;
    s21_set_bit(result, i, res_bit % 2);
  }

  return overflow;
}

int s21_error_add(s21_decimal value_1, s21_decimal value_2) {
  int error = 0;
  s21_decimal tmp_1 = {0};
  s21_decimal tmp_2 = {0};
  bool sign_1 = s21_is_negative(value_1);
  bool sign_2 = s21_is_negative(value_2);

  s21_copy_all_bytes(value_1, &tmp_1);
  s21_copy_all_bytes(value_2, &tmp_2);
  s21_set_plus(&tmp_1);
  s21_set_plus(&tmp_2);
  if (sign_1 == false && sign_2 == false) {
    error = 1;
  } else if (sign_1 == true && sign_2 == true) {
    error = 2;
  } else if (sign_1 == false && sign_2 == true) {
    if (s21_is_less(tmp_1, tmp_2)) {
      error = 2;
    } else {
      error = 1;
    }
  } else if (sign_1 == true && sign_2 == false) {
    if (s21_is_less(tmp_2, tmp_1)) {
      error = 1;
    } else {
      error = 2;
    }
  }

  return error;
}

int s21_root_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
                 bool sign_1, bool sign_2) {
  int error = 0;

  if (sign_1 == true && sign_2 == true) {
    error = s21_support_add(value_1, value_2, result);
    s21_set_minus(result);
  } else if (sign_1 == false && sign_2 == false) {
    error = s21_support_add(value_1, value_2, result);
  } else if (sign_1 == false && sign_2 == true) {
    if (s21_is_less(value_1, value_2)) {
      s21_support_sub(value_2, value_1, result);
      s21_set_minus(result);
    } else {
      s21_support_sub(value_1, value_2, result);
    }
  } else if (sign_1 == true && sign_2 == false) {
    if (s21_is_less(value_2, value_1)) {
      s21_support_sub(value_1, value_2, result);
      s21_set_minus(result);
    } else {
      s21_support_sub(value_2, value_1, result);
    }
  }

  return error;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0;
  s21_decimal tmp_1 = {0}, tmp_2 = {0};
  int scale_1 = s21_get_scale(value_1), scale_2 = s21_get_scale(value_2);
  bool sign_1 = s21_is_negative(value_1), sign_2 = s21_is_negative(value_2);

  s21_init_value(result);
  s21_copy_all_bytes(value_1, &tmp_1);
  s21_copy_all_bytes(value_2, &tmp_2);
  if (scale_1 != scale_2) error = s21_normalize_scale(&tmp_1, &tmp_2);
  if (error) {
    if (sign_1 == false && sign_2 == true) {
      error = 1;
    } else if (sign_1 == true && sign_2 == false)
      error = 2;
  } else {
    s21_set_plus(&tmp_1);
    s21_set_plus(&tmp_2);
    if (sign_1 == false && sign_2 == false) {
      if (s21_is_less(tmp_1, tmp_2)) {
        s21_support_sub(tmp_2, tmp_1, result);
        s21_set_minus(result);
      } else
        s21_support_sub(tmp_1, tmp_2, result);
    } else if (sign_1 == true && sign_2 == true) {
      if (s21_is_less(tmp_1, tmp_2)) {
        s21_support_sub(tmp_2, tmp_1, result);
      } else {
        s21_support_sub(tmp_1, tmp_2, result);
        s21_set_minus(result);
      }
    } else if (sign_1 == false && sign_2 == true) {
      error = s21_support_add(tmp_1, tmp_2, result);
    } else if (sign_1 == true && sign_2 == false) {
      error = s21_support_add(tmp_1, tmp_2, result);
      s21_set_minus(result);
    }
    int scale_res = s21_get_scale(tmp_1);
    s21_set_scale(result, scale_res);
    if (error && s21_is_negative(*result)) {
      error = 2;
    } else if (error && !s21_is_negative(*result))
      error = 1;
  }

  return error;
}

void s21_support_sub(s21_decimal value_1, s21_decimal value_2,
                     s21_decimal *result) {
  s21_init_value(result);

  for (int i = 0; i <= 95; i++) {
    int first_bit = s21_get_bit(value_1, i);
    int second_bit = s21_get_bit(value_2, i);
    s21_set_bit(result, i, first_bit ^ second_bit);
    if (!first_bit && second_bit) {
      int k = i + 1;
      while ((first_bit = s21_get_bit(value_1, k)) != 1) {
        s21_set_bit(&value_1, k, 1);
        k++;
      }
      s21_set_bit(&value_1, k, 0);
    }
  }
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0, overflow = 0;
  s21_decimal tmp = {0};
  s21_decimal tmp_add = {0};
  int scale_1 = s21_get_scale(value_1), scale_2 = s21_get_scale(value_2);
  int scale_res = scale_1 + scale_2;
  bool sign_1 = s21_is_negative(value_1), sign_2 = s21_is_negative(value_2);
  bool sign_res = sign_1 ^ sign_2;

  s21_init_value(result);
  s21_copy_mantis(value_1, &tmp);
  if (!s21_is_null(value_1) &&
      !s21_is_null(
          value_2)) {  // если хотя бы одно значение не ноль, тогда умножаем
    if (s21_is_negative(value_1) ^
        s21_is_negative(
            value_2)) {  // если знаки разные, то результат отрицательный
      s21_set_minus(result);
    } else {  // иначе, результат положительный
      s21_set_plus(result);
    }
    for (int i = 0; i < 95 && !overflow; i++) {
      if (s21_get_bit(value_2, i) == 1) {
        int step = i;
        for (; step > 0 && !overflow; step--) {
          overflow = s21_step_left(&tmp);
        }
        if (!overflow) {
          overflow = s21_support_add(*result, tmp, &tmp_add);
          if (!overflow) {
            s21_copy_mantis(tmp_add, result);
            s21_copy_mantis(value_1, &tmp);
            s21_set_scale(result, scale_res);
          }
        }
      }
    }
    if (overflow) {
      s21_init_value(result);
      if (sign_res) {
        error = 2;
      } else {
        error = 1;
      }
    }
  }

  return error;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0;
  s21_decimal tmp_1 = {0};
  s21_decimal tmp_2 = {0};
  s21_decimal zero = {0};
  bool sign_1 = s21_is_negative(value_1);
  bool sign_2 = s21_is_negative(value_2);
  bool sign_res = sign_1 ^ sign_2;

  s21_init_value(result);
  if (sign_2) {
    s21_set_minus(&zero);
  }
  if (!s21_is_equal(value_2, zero)) {
    s21_copy_all_bytes(value_1, &tmp_1);
    s21_copy_all_bytes(value_2, &tmp_2);
    s21_set_plus(&tmp_1);
    s21_set_plus(&tmp_2);
    int overflow = s21_normalize_scale_for_div(&tmp_1, &tmp_2);
    if (!overflow) {
      error = s21_fractional_division(tmp_1, tmp_2, result);
      if (sign_res) {
        s21_set_minus(result);
      } else {
        s21_set_plus(result);
      }
      if (error && s21_is_negative(*result)) {
        error = 2;
      } else if (error && !s21_is_negative(*result)) {
        error = 1;
      }
    }
  } else {
    error = 3;
  }

  return error;
}

int s21_fractional_division(s21_decimal value_1, s21_decimal value_2,
                            s21_decimal *result) {
  int overflow = 0;
  s21_decimal before_point = {0};
  s21_decimal int_res = {0};
  s21_decimal dec_mod = {0};
  s21_decimal after_point = {0};
  s21_decimal div_rem = {0};
  s21_decimal zero = {0};
  s21_decimal one = {{1, 0, 0, 0}};
  s21_decimal ten = {{10, 0, 0, 0}};
  s21_decimal max = {{0xff, 0xff, 0xff, 0}};  // 4294967295
  int scale_res = s21_get_scale(value_1);

  s21_truncate(value_1, &before_point);
  s21_support_div(before_point, value_2, &int_res);
  s21_mul(int_res, value_2, &dec_mod);
  s21_support_sub(before_point, dec_mod, &dec_mod);
  if (s21_is_equal(int_res, zero) || s21_is_equal(dec_mod, max)) {
    s21_copy_all_bytes(one, result);
  } else {
    if (s21_is_equal(dec_mod, zero)) {
      s21_copy_all_bytes(int_res, result);
    } else {
      for (int i = 0; i < scale_res; i++) {
        s21_support_mul(dec_mod, ten, &dec_mod);
      }
      s21_sub(value_1, before_point, &after_point);
      s21_support_add(dec_mod, after_point, &after_point);
      s21_set_scale(&div_rem, scale_res);
      overflow = s21_remainder_division(after_point, value_2, &div_rem);

      int scale_div_rem = s21_get_scale(div_rem);
      for (int i = 0; i < scale_div_rem; i++) {
        s21_mul(int_res, ten, &int_res);
      }
      s21_support_add(int_res, div_rem, result);
      scale_res = s21_get_scale(div_rem);
      s21_set_scale(result, scale_res);
    }
  }

  return overflow;
}

s21_decimal s21_support_div(s21_decimal value_1, s21_decimal value_2,
                            s21_decimal *result) {
  s21_decimal fmod = {0};
  s21_decimal tmp = {0};

  s21_init_value(result);
  if (s21_is_greater_or_equal(value_1, value_2)) {
    s21_set_bit(&tmp, 0, 1);
  }
  if (s21_is_greater(value_1, value_2)) {
    int flag = 1;
    while (flag) {
      s21_decimal copy_dec2 = value_2;
      while (
          s21_is_greater_or_equal(value_1, copy_dec2) &&
          !(s21_get_bit(value_1, 95) || s21_get_bit(copy_dec2, 95))) {  //&& &&
        s21_step_left(&copy_dec2);
        s21_step_left(&tmp);
      }
      if (!(s21_get_bit(value_1, 95) || s21_get_bit(copy_dec2, 95)) ||
          (s21_is_greater_or_equal(copy_dec2, value_1))) {  // && ||
        s21_step_right(&copy_dec2);
        s21_step_right(&tmp);
      }
      s21_support_sub(value_1, copy_dec2, &value_1);
      if (result) {
        s21_support_add(*result, tmp, result);
      }
      s21_init_value(&tmp);
      s21_set_bit(&tmp, 0, 1);
      if (s21_is_less(value_1, value_2)) {
        flag = 0;
      }
    }
  }
  fmod = value_1;

  return fmod;
}

int s21_remainder_division(s21_decimal value_1, s21_decimal value_2,
                           s21_decimal *result) {
  int overflow = 0;
  s21_decimal int_res = {0};
  s21_decimal dec_mod = {0};
  s21_decimal zero = {0};
  s21_decimal ten = {{10, 0, 0, 0}};
  int scale_div = s21_get_scale(*result);

  if (scale_div < 27) {
    if (s21_is_less(value_1, value_2)) {
      s21_support_mul(value_1, ten, &value_1);
      scale_div++;
      s21_set_scale(result, scale_div);
      s21_remainder_division(value_1, value_2, result);
    } else {
      s21_support_div(value_1, value_2, &int_res);
      s21_support_mul(int_res, value_2, &dec_mod);
      s21_support_sub(value_1, dec_mod, &dec_mod);
      if (!s21_is_equal(dec_mod, zero)) {
        s21_set_scale(&dec_mod, scale_div && overflow == 0);
        overflow = s21_remainder_division(dec_mod, value_2, &dec_mod);
        scale_div = s21_get_scale(dec_mod);
        for (int i = 0; i < scale_div - 1; i++) {
          s21_support_mul(int_res, ten, &int_res);
        }
        s21_support_add(int_res, dec_mod, result);
        s21_set_scale(result, scale_div);
      } else {
        s21_copy_all_bytes(int_res, result);
        s21_set_scale(result, scale_div);
      }
    }
  } else {
    overflow = 1;
  }

  return overflow;
}
