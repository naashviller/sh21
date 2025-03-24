#include "s21_help_function.h"

bool s21_is_negative(s21_decimal value) {
  bool flag = false;

  if (value.bits[3] & MINUS) {
    flag = true;  // число отрицательное
  }

  return flag;
}

// сделать число отрицательным
void s21_set_minus(s21_decimal *value) { value->bits[3] |= MINUS; }

// сделать число положительным
void s21_set_plus(s21_decimal *value) { value->bits[3] &= ~MINUS; }

bool s21_is_null(s21_decimal value) {
  bool flag = false;

  if (((value.bits[0]) == ZERO) && ((value.bits[1]) == ZERO) &&
      ((value.bits[2]) == ZERO)) {
    flag = true;  // число равно нулю
  }

  return flag;
}

void s21_init_value(s21_decimal *value) {
  for (int i = 0; i < 128; i++) {
    s21_set_bit(value, i, 0);
  }
}

int s21_get_scale(s21_decimal value) { return ((value.bits[3] & SCALE) >> 16); }

void s21_set_scale(s21_decimal *value, int scale) {
  value->bits[3] &= MINUS;
  value->bits[3] |= (scale << 16) & SCALE;
}

int s21_get_bit(s21_decimal value, int indexbit) {
  int bit_value = 0;
  int num_bait = indexbit / 32;
  int num_bit = indexbit % 32;
  unsigned int n = (1u << num_bit);

  if ((value.bits[num_bait] & n) != 0) {
    bit_value = 1;
  }

  return bit_value;
}

void s21_set_bit(s21_decimal *value, int indexbit, int setbit) {
  int num_bait = indexbit / 32;
  int num_bit = indexbit % 32;

  if (setbit == 1) {
    value->bits[num_bait] |= (1 << num_bit);
  } else if (setbit == 0) {
    value->bits[num_bait] &= ~(1 << num_bit);
  }
}

int s21_step_left(s21_decimal *value) {
  int full = s21_get_bit(*value, 95);

  for (int i = 95; i >= 0; i--) {
    if (i != 0) {
      s21_set_bit(value, i, s21_get_bit(*value, i - 1));
    } else {
      s21_set_bit(value, i, 0);
    }
  }

  return full;
}

int s21_step_right(s21_decimal *value) {
  int full = s21_get_bit(*value, 0);  //(*value, 1)

  for (int i = 0; i <= 95; i++) {
    if (i != 95) {
      s21_set_bit(value, i, s21_get_bit(*value, i + 1));
    } else {
      s21_set_bit(value, i, 0);
    }
  }

  return full;
}

void s21_copy_all_bytes(s21_decimal src, s21_decimal *dst) {
  for (int i = 0; i < 4; i++) {
    dst->bits[i] = src.bits[i];
  }
}

void s21_copy_mantis(s21_decimal src, s21_decimal *dst) {
  for (int i = 0; i < 3; i++) {
    dst->bits[i] = src.bits[i];
  }
}

int s21_normalize_scale(s21_decimal *value_1, s21_decimal *value_2) {
  int overflow = 0;
  int scale_1 = s21_get_scale(*value_1);
  int scale_2 = s21_get_scale(*value_2);
  s21_decimal ten = {{10, 0, 0, 0}};

  if (scale_1 != scale_2) {
    if (scale_1 > scale_2) {
      int div_scale = scale_1 - scale_2;
      for (int i = 0; i < div_scale && !overflow; i++) {
        overflow = s21_mul(*value_2, ten, value_2);
        s21_set_scale(value_2, ++scale_2);
      }
    } else {
      int div_scale = scale_2 - scale_1;
      for (int i = 0; i < div_scale && !overflow; i++) {
        overflow = s21_mul(*value_1, ten, value_1);
        s21_set_scale(value_1, ++scale_1);
      }
    }
  }

  return overflow;
}

int s21_normalize_scale_for_div(s21_decimal *value_1, s21_decimal *value_2) {
  s21_decimal ten = {{10, 0, 0, 0}};
  int scale_1 = s21_get_scale(*value_1);
  int scale_2 = s21_get_scale(*value_2);
  int overflow = 0;

  while (scale_2 > 0 && !overflow) {
    if (scale_1 == 0) {
      overflow = s21_support_mul(*value_1, ten, value_1);
    } else {
      s21_set_scale(value_1, --scale_1);
    }
    s21_set_scale(value_2, --scale_2);
  }

  return overflow;
}

int s21_support_mul(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result) {
  int overflow = 0;
  int counter_set_bit = s21_bit_counter(value_2);

  s21_init_value(result);
  for (int i = 0; i < counter_set_bit && overflow == 0; i++) {
    if (s21_get_bit(value_2, i) == 1) {
      overflow = s21_support_add(*result, value_1, result);
    }
    if (s21_step_left(&value_1) && i != counter_set_bit - 1) {
      overflow = 1;
    }
  }
  if (overflow) {
    s21_init_value(result);
  }

  return overflow;
}

int s21_bit_counter(s21_decimal value) {
  int res = 0;
  for (int i = 0; i <= 95; i++) {
    if (s21_get_bit(value, i) == 1) {
      res = i;
    }
  }
  if (res != 0) {
    res++;
  }

  return res;
}

int s21_support_truncate(s21_decimal value, s21_decimal *result) {
  int error = 0;
  int scale_dec = s21_get_scale(value);
  int sign_dec = s21_is_negative(value);

  unsigned long long int int_num = 0;
  long double double_num = s21_convert_mantisa_to_double(value);
  if (scale_dec != 0) {
    for (int i = 0; i < scale_dec; i++) {
      double_num = double_num / 10;
    }
  }

  int_num = (unsigned long long int)double_num;
  s21_from_ullint_to_decimal(int_num, result);
  if (sign_dec) {
    s21_set_minus(result);
  } else {
    s21_set_plus(result);
  }

  return error;
}

long double s21_convert_mantisa_to_double(s21_decimal src) {
  long double result = 0;
  for (int i = 95; i >= 0; i--) {
    if (result >= (-1 * INT_MIN) || result <= INT_MAX) {
      result = result * 2 + s21_get_bit(src, i);
    }
  }
  return result;
}

void s21_from_ullint_to_decimal(unsigned long long int src, s21_decimal *dst) {
  if (dst && src != S21_INFINITY && src != S21_NAN) {
    s21_init_value(dst);
    for (unsigned int i = 0; i < 64; i++) {
      s21_set_bit(dst, i, s21_get_bit_ullint(src, i));
    }
  }
}

int s21_get_bit_ullint(unsigned long long int num, int indexbit) {
  int sign = 0;
  if ((num & (1ull << indexbit)) == 0)
    sign = 0;
  else
    sign = 1;
  return sign;
}

void s21_set_bit_int(int *int_d, int position, int flag) {
  if (flag)
    *int_d |= 1 << position;
  else
    *int_d &= ~(1 << position);
}

int s21_get_exp(unsigned int fbits) {
  int mask = 0b01111111100000000000000000000000;
  int exp = ((fbits & mask) >> 23);

  return exp - 127;
}

int s21_get_bit_float(float src, int position) {
  unsigned int mask = 1u << position;
  unsigned int mantissa_bit = *((unsigned int *)&src);
  return !!(mask & mantissa_bit);
}
