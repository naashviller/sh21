#ifndef S21_MATH_H
#define S21_MATH_H

#define s21_E 2.7182818284590452354       /* e */
#define s21_LOG2E 1.4426950408889634074   /* log_2 e */
#define s21_LOG10E 0.43429448190325182765 /* log_10 e */
#define s21_LN2 0.69314718055994530942    /* log_e 2 */
#define s21_LN10 2.30258509299404568402   /* log_e 10 */
#define s21_PI 3.14159265358979323846     /* pi */
#define s21_PI_2 1.57079632679489661923   /* pi/2 */
#define s21_2PI 6.2831853071795864768     /* 2pi */
#define s21_NAN 0.0 / 0.0
#define s21_INF 1.0 / 0.0
#define s21_NEG_INF -1.0 / 0.0
#define s21_EPS 1e-17
#define s21_MAX_DOUBLE 1.79769313486231571e+308
#define s21_LN10 2.30258509299404568402

// вычисляет абсолютное значение целого числа
int s21_abs(int x);
// вычисляет абсолютное значение числа с плавающей точкой
long double s21_fabs(double x);
// возводит число в заданную степень
long double s21_pow(double base, double exp);
// вычисляет арккосинус
long double s21_acos(double x);
// вычисляет арксинус
long double s21_asin(double x);
// вычисляет арктангенс
long double s21_atan(double x);
// возвращает ближайшее целое число, не меньшее заданного значения
long double s21_ceil(double x);
// вычисляет косинус
long double s21_cos(double x);
// возвращает значение e, возведенное в заданную степень
long double s21_exp(double x);
// возвращает ближайшее целое число, не превышающее заданное значение
long double s21_floor(double x);
// остаток операции деления с плавающей точкой
long double s21_fmod(double x, double y);
// вычисляет натуральный логарифм
long double s21_log(double x);
// вычисляет синус
long double s21_sin(double x);
// вычисляет квадратный корень
long double s21_sqrt(double x);
// вычисляет тангенс
long double s21_tan(double x);

#endif /* S21_MATH_H */
