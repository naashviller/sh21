
#include "../s21_decimal.h"
#include "s21_help_function.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int result = OK;
  if (dst) {
    s21_init_value(dst);
    if (src < 0) {
      dst->bits[0] = -src;
      s21_set_minus(dst);
    } else if (src >= 0) {
      dst->bits[0] = src;
    }
  } else
    result = ERROR;
  return result;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int result = OK;
  if (dst && !isnan(src) && !isinf(src)) {
    s21_init_value(dst);
    if (src < 0 || signbit(src)) {
      s21_set_minus(dst);
      src *= -1;
    }
    if (src != 0.0) {
      int scale = 0;
      unsigned int fbits = *((unsigned int *)&src);
      int bin_exp = s21_get_exp(fbits);
      double src_n = (double)src;
      while (src_n < 1) {
        src_n *= 10;
        scale++;
      }
      while ((int)src_n / (int)1e7 == 0) {
        src_n *= 10;
        scale++;
      }
      src_n = round(src_n);
      if (scale > 28 || bin_exp < -94 || bin_exp > 95) result = ERROR;
      if (!result) {
        for (; fmod(src_n, 10) == 0 && scale > 0;
             scale--, src_n *= pow(10, -1)) {
        }
        src = (float)src_n;
        fbits = *((unsigned int *)&src);
        bin_exp = s21_get_exp(fbits);
        dst->bits[bin_exp / 32] |= 1u << (bin_exp % 32);
        s21_set_scale(dst, scale);
        for (int i = bin_exp - 1, m = 22; m >= 0; i--, m--) {
          s21_set_bit(dst, i, s21_get_bit_float(src, m));
        }
      }
    }
  } else
    result = ERROR;
  return result;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int result = OK;
  s21_truncate(src, &src);
  if (dst) {
    if (src.bits[1] != 0 || src.bits[2] != 0) {
      result = ERROR;
    }
    if (!result) {
      for (int i = 0; i < 32; i++) s21_set_bit_int(dst, i, s21_get_bit(src, i));
      if (s21_get_bit(src, 127)) *dst *= -1;
    }
  } else
    result = ERROR;
  return result;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int result = OK;
  if (dst && s21_get_scale(src) < 29) {
    double temp = 0.0;
    for (int i = 0; i < 96; ++i) {
      if (s21_get_bit(src, i)) temp += pow(2.0, i);
    }
    int scale = s21_get_scale(src);
    temp *= pow(10.0, -scale);
    if (s21_get_bit(src, 127)) temp *= -1.0;
    *dst = (float)temp;
  } else
    result = ERROR;
  return result;
}
