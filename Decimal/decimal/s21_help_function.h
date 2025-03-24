#ifndef S21_HELP_FUNCTION
#define S21_HELP_FUNCTION

#include "../s21_decimal.h"

bool s21_is_negative(s21_decimal value);
void s21_set_minus(s21_decimal *value);
void s21_set_plus(s21_decimal *value);
bool s21_is_null(s21_decimal value);
void s21_init_value(s21_decimal *value);
int s21_get_scale(s21_decimal value);
void s21_set_scale(s21_decimal *value, int scale);
int s21_get_bit(s21_decimal value, int indexbit);
void s21_set_bit(s21_decimal *value, int indexbit, int setbit);
int s21_step_left(s21_decimal *value);
int s21_step_right(s21_decimal *value);
void s21_copy_all_bytes(s21_decimal src, s21_decimal *dst);
void s21_copy_mantis(s21_decimal src, s21_decimal *dst);
int s21_normalize_scale(s21_decimal *value_1, s21_decimal *value_2);
int s21_normalize_scale_for_div(s21_decimal *value_1, s21_decimal *value_2);
void s21_set_bit_int(int *int_d, int position, int flag);
int s21_get_exp(unsigned int fbits);
int s21_get_bit_float(float src, int position);

int s21_support_mul(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result);
int s21_bit_counter(s21_decimal value);

int s21_support_truncate(s21_decimal value, s21_decimal *result);
long double s21_convert_mantisa_to_double(s21_decimal src);
void s21_from_ullint_to_decimal(unsigned long long int src, s21_decimal *dst);
int s21_get_bit_ullint(unsigned long long int num, int indexbit);

#endif
