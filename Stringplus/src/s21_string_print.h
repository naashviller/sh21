#ifndef S21_STRING_PRINT_H
#define S21_STRING_PRINT_H

#include <math.h>
#include <stdarg.h>
#include <stdint.h>

#include "s21_string.h"

#define BUFF_SIZE_PRINT 8000

typedef struct {
  char plus;
  char minus;
  char space;
  bool zero;
  bool octotorp;
  char specifier;
  bool flag;
  int width;
  bool precision_set;
  int precision;
  char length;
} Flags;

const char *GetFlag(const char *format, Flags *property);
const char *GetWidth(const char *format, Flags *property, va_list *va);
const char *GetPrecision(const char *format, Flags *property, va_list *va);
const char *GetLength(const char *format, Flags *property);
void Specifier(Flags *property, char *buff, va_list *va, int *chflag);
void ParseInt(Flags *property, char *buff, va_list *va);
void IntToString(Flags *property, int64_t value, char *buff, int base);
void IntFlags(Flags *property, char *buff, bool value_sign);
void IntPrecision(Flags *property, char *buff);
void IntWidth(Flags *property, char *buff);
void ParseChar(Flags *property, char *buff, va_list *va, int *chflag);
void ParseFloat(Flags *property, char *buff, va_list *va, long double value);
void FloatPrecision(Flags *property, char *buff);
int Foo(long double d);
int Boo(long long x);
void FloatToString(Flags *property, long double value, char *buff, int base);
void ParseMantis(Flags *property, char *buff, va_list *va, long double value);
void MantisToString(Flags *property, int count, char *buff, bool sign_value);
void ParseString(Flags *property, char *buff, va_list *va);
void StringPrecision(Flags *property, char *buff);
void ParseUnsign(Flags *property, char *buff, va_list *va);
void UnsToString(Flags *property, int64_t value, char *buff, int base);
void ParsePointer(Flags *property, char *buff, va_list *va);
void ParseOctal(Flags *property, char *buff, va_list *va);
void ParseHex(Flags *property, char *buff, va_list *va);

#endif