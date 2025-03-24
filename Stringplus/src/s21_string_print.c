#include "s21_string_print.h"

int s21_sprintf(char *restrict str, const char *restrict format, ...) {
  Flags property = {0};
  va_list va;
  int chflag = 0;

  va_start(va, format);
  char *start = str;
  while (*format) {
    bool contin = true;
    if (*format != '%') {
      if (chflag == 0)
        *str++ = *format++;
      else {
        *str++ = '\0';
        format++;
      }
      contin = false;
    } else {
      format++;
      s21_memset(&property, 0, sizeof(Flags));
    }
    if (contin) {
      format = GetFlag(format, &property);
      format = GetWidth(format, &property, &va);
      format = GetPrecision(format, &property, &va);
      format = GetLength(format, &property);
      property.specifier = *format;
      format++;
      char buff[BUFF_SIZE_PRINT] = {'\0'};
      Specifier(&property, buff, &va, &chflag);
      for (int i = 0; buff[i]; i++, str++) {
        if (chflag == 0)
          *str = buff[i];
        else
          *str = '\0';
      }
      if (property.specifier == 'n') {
        int *temp = va_arg(va, int *);
        *temp = str - start;
      }
    }
  }
  if (chflag == -1) {
    for (char *temp = start; *temp; temp++) *temp = '\0';
  }
  *str = '\0';
  va_end(va);

  return (chflag == -1) ? -1 : str - start;
}

const char *GetFlag(const char *format, Flags *property) {
  while (*format == '+' || *format == '-' || *format == ' ' || *format == '#' ||
         *format == '0') {
    if (*format == '+') {
      property->plus = '+';
      property->flag = true;
      format++;
    } else if (*format == '-') {
      property->minus = '-';
      property->flag = true;
      format++;
    } else if (*format == ' ') {
      property->space = ' ';
      property->flag = true;
      format++;
    } else if (*format == '0') {
      property->zero = '0';
      format++;
    } else if (*format == '#') {
      property->octotorp = '#';
      format++;
    }
  }

  return format;
}

const char *GetWidth(const char *format, Flags *property, va_list *va) {
  if (*format == '*') {
    format++;
    property->width = va_arg(*va, int);
  } else if (*format > 47 && *format < 58) {
    char tmp[BUFF_SIZE_PRINT] = {'\0'};
    for (int i = 0; *format > 47 && *format < 58; i++, format++) {
      tmp[i] = *format;
    }
    property->width = s21_atoi(tmp);
  }

  return format;
}

const char *GetPrecision(const char *format, Flags *property, va_list *va) {
  if (*format == '.') {
    property->precision_set = true;
    format++;
    if (*format == '*') {
      format++;
      property->precision = va_arg(*va, int);
    } else if (*format > 47 && *format < 58) {
      char tmp[BUFF_SIZE_PRINT] = {'\0'};
      for (int i = 0; *format > 47 && *format < 58; i++, format++) {
        tmp[i] = *format;
      }
      property->precision = s21_atoi(tmp);
    }
  }

  return format;
}

const char *GetLength(const char *format, Flags *property) {
  if (*format == 'h') {
    property->length = 'h';
    format++;
  } else if (*format == 'l') {
    property->length = 'l';
    format++;
  } else if (*format == 'L') {
    property->length = 'L';
    format++;
  }

  return format;
}

void Specifier(Flags *property, char *buff, va_list *va, int *chflag) {
  if (property->specifier == 'd' || property->specifier == 'i') {
    ParseInt(property, buff, va);
  } else if (property->specifier == 'c') {
    ParseChar(property, buff, va, chflag);
  } else if (property->specifier == 'f') {
    ParseFloat(property, buff, va, 0);
  } else if (property->specifier == 's') {
    ParseString(property, buff, va);
  } else if (property->specifier == 'u') {
    ParseUnsign(property, buff, va);
  } else if (property->specifier == '%') {
    buff[0] = '%';
  } else if (property->specifier == 'p') {
    ParsePointer(property, buff, va);
  } else if (property->specifier == 'o') {
    ParseOctal(property, buff, va);
  } else if (property->specifier == 'x' || property->specifier == 'X') {
    ParseHex(property, buff, va);
  } else if (property->specifier == 'e' || property->specifier == 'E') {
    ParseMantis(property, buff, va, 0);
  }
}

void ParseInt(Flags *property, char *buff, va_list *va) {
  long long int value = va_arg(*va, long long int);

  if (property->length == 0) {
    value = (int)value;
  } else if (property->length == 'h') {
    value = (short int)value;
  } else if (property->length == 'l') {
    value = (long int)value;
  }

  bool value_sign = false;
  if (value < 0) value_sign = true;
  IntToString(property, value, buff, 10);
  if (property->flag) {
    IntFlags(property, buff, value_sign);
  }
  if (property->precision_set) {
    IntPrecision(property, buff);
  }
  if (property->width) {
    IntWidth(property, buff);
  }
}

void IntToString(Flags *property, int64_t value, char *buff, int base) {
  int counter = 0;
  long long int temp = value;
  bool sing = false;

  for (; temp; temp /= base) {
    counter++;
  }
  if (value < 0) {
    value *= -1;
    buff[0] = '-';
    sing = true;
  }
  if ((property->precision == 0 && property->precision_set == true) &&
      value == 0 &&
      (property->specifier == 'f' || property->specifier == 'e' ||
       property->specifier == 'E')) {
    buff[0] = '0';
  } else if ((property->precision == 0 && property->precision_set == true) &&
             value == 0) {
    buff[0] = ' ';
  } else if (value == 0) {
    buff[0] = '0';
  }
  if (value > 0) {
    counter = sing ? counter : counter - 1;
    for (; sing ? counter > 0 : counter >= 0; counter--) {
      buff[counter] = "0123456789abcdef"[value % base];
      value /= base;
    }
  }
}

void IntFlags(Flags *property, char *buff, bool value_sign) {
  int counter = 0;
  char *p = buff;

  for (; *p; p++) {
    counter++;
  }
  if ((property->plus || property->space) && buff[0] != '-') {
    for (; counter - 1 >= 0; counter--) {
      buff[counter] = buff[counter - 1];
    }
    if (property->plus) {
      if (!value_sign)
        buff[0] = '+';
      else
        buff[0] = '-';
    } else if (property->space) {
      if (!value_sign)
        buff[0] = ' ';
      else
        buff[0] = '-';
    }
  }
}

void IntPrecision(Flags *property, char *buff) {
  int counter = 0;
  int counter1 = 0;
  int prefix = 0;
  char *p = buff;
  bool check_sing =
      (buff[0] == '+' || buff[0] == '-' || (buff[0] == ' ' && property->space))
          ? true
          : false;

  for (; *p; p++) {
    counter++;
  }
  if (property->precision == 0 && counter == 1 && buff[0] == '0') {
    buff[0] = '\0';
  } else if (property->precision > 0) {
    for (; *p; p++) {
      counter++;
    }
    if (property->octotorp) {
      if (property->specifier == 'x' || property->specifier == 'X') {
        prefix += 2;
      }
    }
    if (property->precision >= (check_sing ? counter - 1 : counter - prefix)) {
      counter1 =
          check_sing ? property->precision + 1 : property->precision + prefix;
      for (; check_sing ? counter - 1 > 0 : counter - 1 >= 0 + prefix;
           counter1--, counter--) {
        buff[counter1 - 1] = buff[counter - 1];
      }
      for (; check_sing ? counter1 - 1 > 0 : counter1 - 1 >= 0 + prefix;
           counter1--) {
        buff[counter1 - 1] = '0';
      }
    }
  }
}

void IntWidth(Flags *property, char *buff) {
  int counter = 0;
  char *p = buff;
  int size = property->width;

  for (; *p; p++) {
    counter++;
  }
  if (size > counter) {
    if (!property->minus) {
      for (; size - 1 >= 0 && counter - 1 >= 0; counter--, size--) {
        buff[size - 1] = buff[counter - 1];
      }
      bool flag = true;
      for (; flag ? size - 1 >= 0 : size - 1 > 0; size--) {
        if (property->zero) {
          if ((property->specifier == 'f' || property->specifier == 'e' ||
               property->specifier == 'E') ||
              (!property->precision_set &&
               (property->specifier != 's' || property->specifier != 'c'))) {
            if (buff[size] == '+' || buff[size] == '-' ||
                (buff[0] == ' ' && property->space)) {
              buff[0] = buff[size];
              buff[size] = '0';
              flag = false;
            }
            buff[size - 1] = '0';
          } else {
            buff[size - 1] = ' ';
          }
        } else {
          buff[size - 1] = ' ';
        }
      }
    } else {
      for (; counter < size; counter++) {
        buff[counter] = ' ';
      }
    }
  }
}

void ParseChar(Flags *property, char *buff, va_list *va, int *chflag) {
  unsigned char value = 0;

  if (property->length == 0) {
    value = (unsigned char)va_arg(*va, int);
  } else if (property->length == 'l') {
    value = (wchar_t)value;
    wchar_t value = va_arg(*va, wchar_t);
    if (value < 0 || value > 255) *chflag = -1;
    char s[BUFF_SIZE_PRINT] = {'\0'};
    wctomb(s, value);
    char *p = s;
    for (int temp = 0; *p; p++, temp++) {
      buff[temp] = *p;
    }
  }

  if (!(property->length == 'l')) {
    if (value == '\0') {
      if (*chflag != -1) {
        *chflag = 1;
        buff[0] = '0';
      }
    } else {
      buff[0] = value;
    }
  }
  if (property->width) {
    IntWidth(property, buff);
  }
}

void ParseFloat(Flags *property, char *buff, va_list *va, long double value) {
  if (!value) {
    if (property->length == 0 || property->length == 'l') {
      value = (double)value;
      value = va_arg(*va, double);
    } else if (property->length == 'L') {
      value = (long double)value;
      value = va_arg(*va, long double);
    }
  }

  bool value_sign = false;
  if (value < 0) value_sign = true;
  FloatToString(property, value, buff, 10);
  if (property->flag) {
    IntFlags(property, buff, value_sign);
  }
  if (property->precision_set) {
    FloatPrecision(property, buff);
  }
  if (property->width) {
    IntWidth(property, buff);
  }
}

void FloatToString(Flags *property, long double value, char *buff, int base) {
  bool sign = false;
  bool pres_flag = false;

  if (!property->precision_set) {
    property->precision_set = true;
    pres_flag = true;
    property->precision = 6;
  }
  if (value < 0) {
    buff[0] = '-';
    sign = true;
  }
  int counter = sign ? Boo(value) + 1 : Boo(value);
  int afterPoint = 0;
  if (property->precision_set) {
    afterPoint = property->precision + 1;
  } else {
    afterPoint = 7;
  }
  long long int ipart = (long long int)value;
  long double fpart =
      sign ? (long double)ipart - value : value - (long double)ipart;
  if (ipart == 0 && pres_flag && !property->zero && !property->plus &&
      !property->space && !property->minus && !property->octotorp)
    IntToString(property, ipart, buff + 1, base);
  else
    IntToString(property, ipart, buff, base);
  buff[counter] = '.';
  if (afterPoint != 0 && fpart != 0) {
    long double temp = fpart;
    for (; temp < 0.1;) {
      temp *= base;
      buff[++counter] = '0';
    }
  }
  if (fpart == 0) {
    for (int temp = 0; temp < property->precision; temp++) {
      buff[++counter] = '0';
    }
  }
  fpart = fpart * pow(10, afterPoint);
  IntToString(property, (int)fpart, buff + counter + 1, base);
}

void FloatPrecision(Flags *property, char *buff) {
  int counter = 0;
  int counter1 = 0;
  char *p = buff;
  bool flag = false;

  for (; *p; p++) {
    if (flag) counter++;
    if (*p == '.') flag = true;
    counter1++;
  }
  if (property->precision > counter) {
    for (; property->precision > counter; counter++, counter1++)
      buff[counter1] = '0';
  } else {
    if (buff[counter1 - 1] != '0' || buff[counter1 - 1] != '.') {
      int per = s21_atoi(&buff[counter1 - 1]);
      if (per >= 5) {
        int temp = 0;
        if (buff[counter1 - 2] == '.') {
          int temp2 = s21_atoi(&buff[counter1 - 3]) + 1;
          buff[counter1 - 3] = "0123456789abcdef"[temp2 % 10];
          if (!property->octotorp) buff[counter1 - 2] = '\0';
        } else {
          temp = ((s21_atoi(&buff[counter1 - 2]) - per) / 10) + 1;
          buff[counter1 - 2] = "0123456789abcdef"[temp % 10];
          buff[counter1 - 1] = '\0';
        }
        if (temp == 10) {
          if (buff[counter1 - 3] == '.') {
            int temp1 = s21_atoi(&buff[counter1 - 4]) + 1;
            buff[counter1 - 4] = "0123456789abcdef"[temp1 % 10];
            buff[counter1 - 3] = '\0';
            buff[counter1 - 2] = '\0';
          } else {
            int temp1 = ((s21_atoi(&buff[counter1 - 3])) / 10) + 1;
            buff[counter1 - 3] = "0123456789abcdef"[temp1 % 10];
          }
        }
      } else if (property->precision == 0) {
        buff[counter1 - 2] = '\0';
      }
    }
  }
  buff[counter1 - 1] = '\0';
}

int Foo(long double d) {
  long int test = (long int)d;
  int count = 0;

  while (test != d) {
    count++;
    d *= 10;
    test = (long int)d;
  }

  return count;
}

int Boo(long long x) {
  int ret = 0;

  do ret++;
  while (x /= 10);

  return ret;
}

void ParseMantis(Flags *property, char *buff, va_list *va, long double value) {
  if (!value) {
    if (property->length == 0) {
      value = (float)value;
      value = va_arg(*va, double);
    } else if (property->length == 'l') {
      value = (double)value;
      value = va_arg(*va, double);
    } else if (property->length == 'L') {
      value = (long double)value;
      value = va_arg(*va, long double);
    }
  }
  int count = 0;
  bool sign_value = false;
  int e_w = -2;
  if (value == 0)
    count = 0;
  else {
    if (value < 0) sign_value = true;
    if (value >= 1 || value <= -1) {
      for (; value > 9 || value < -9; value /= 10) {
        if (value) count++;
      }
    } else {
      for (; value < 1 && value > -1; value *= 10) {
        if (value) count--;
      }
    }
  }
  for (int temp = count; temp; temp /= 10) e_w++;
  if (e_w < 0) e_w = 0;
  FloatToString(property, value, buff, 10);
  if (property->flag) IntFlags(property, buff, sign_value);
  if (property->precision_set) FloatPrecision(property, buff);
  if (!property->minus) property->width -= 4 + e_w;
  if (property->width) IntWidth(property, buff);
  MantisToString(property, count, buff, sign_value);
}

void MantisToString(Flags *property, int count, char *buff, bool sign_value) {
  bool sign = false;
  int pres = 2;

  if (count < 0) {
    count *= -1;
    sign = true;
  }
  if (property->octotorp && property->precision == 0 &&
      property->width + 4 > property->precision + 6) {
  } else if (property->octotorp && property->precision == 0) {
    pres++;
  }
  if (property->space && property->minus &&
      (property->width + 4 > property->precision + 6) &&
      property->precision != 0) {
    pres -= (property->width + 4 - property->precision - 6) - 1;
  } else if (property->minus &&
             (property->width + 4 > property->precision + 6) &&
             (property->space || property->precision == 0)) {
    pres -= (property->width + 4 - property->precision - 6);
  } else if (property->minus &&
             (property->width + 4 > property->precision + 6)) {
    pres -= (property->width + 4 - property->precision - 6) - 1;
  }
  if (property->width + 4 > property->precision + 6)
    pres += (property->width + 4 - property->precision - 6);
  else
    pres += sign_value ? 1 : 0;
  if (!(property->width + 4 > property->precision + 6) &&
      property->precision == 0)
    pres--;
  if (property->specifier == 'E')
    buff[pres + property->precision] = 'E';
  else
    buff[pres + property->precision] = 'e';
  buff[pres + property->precision + 1] = sign ? '-' : '+';
  int counter = Boo(count);
  if (counter == 1) {
    buff[pres + property->precision + 2] = '0';
    buff[pres + property->precision + 3] = "0123456789"[count % 10];
  } else {
    for (; counter; counter--) {
      buff[pres + property->precision + 1 + counter] = "0123456789"[count % 10];
      count /= 10;
    }
  }
}

void ParseString(Flags *property, char *buff, va_list *va) {
  char *value = va_arg(*va, char *);

  if (value != s21_NULL) {
    int counter = 0;

    char *p = value;
    for (; *p; p++) {
      counter++;
    }
    for (int temp = 0; temp != counter; temp++) {
      buff[temp] = value[temp];
    }
    buff[counter] = '\0';
    if (property->precision_set) {
      StringPrecision(property, buff);
    }
    if (property->width) {
      IntWidth(property, buff);
    }
  }
}

void StringPrecision(Flags *property, char *buff) {
  int counter = 0;
  int counter1 = 0;
  char *p = buff;

  if (property->precision >= 0) {
    for (; *p; p++) {
      counter++;
    }
    if (property->precision >= counter) {
      if (property->precision > property->width && (property->width)) {
        counter1 = property->width;
      } else if (counter < property->width) {
        counter1 = property->precision;
      } else {
        counter1 = counter;
      }
    } else {
      counter1 = property->precision;
      counter = property->precision;
    }
    for (int temp = counter1; temp < BUFF_SIZE_PRINT; temp++) {
      buff[temp] = '\0';
    }
    for (; counter - 1 >= 0; counter1--, counter--) {
      buff[counter1 - 1] = buff[counter - 1];
    }
    for (; counter1 - 1 >= 0; counter1--) {
      buff[counter1 - 1] = ' ';
    }
  }
}

void ParseUnsign(Flags *property, char *buff, va_list *va) {
  long long unsigned int value = va_arg(*va, long long unsigned int);

  if (property->length == 0) {
    value = (unsigned int)value;
  } else if (property->length == 'h') {
    value = (short unsigned int)value;
  } else if (property->length == 'l') {
    value = (long unsigned int)value;
  }

  UnsToString(property, value, buff, 10);
  if (property->precision_set) {
    IntPrecision(property, buff);
  }
  if (property->width) {
    IntWidth(property, buff);
  }
}

void UnsToString(Flags *property, int64_t value, char *buff, int base) {
  int counter = 0;
  int prefix = 0;
  unsigned int temp = value;

  for (; temp; temp /= base) {
    counter++;
  }
  if (value == 0) {
    buff[0] = '0';
  } else {
    if (property->octotorp) {
      if (property->specifier == 'o') {
        buff[0] = '0';
        counter++;
        prefix++;
      } else if (property->specifier == 'x') {
        buff[0] = '0';
        buff[1] = 'x';
        counter += 2;
        prefix += 2;
      } else if (property->specifier == 'X') {
        buff[0] = '0';
        buff[1] = 'X';
        counter += 2;
        prefix += 2;
      }
    }
    for (; counter - 1 >= 0 + prefix; counter--) {
      if (property->specifier == 'X') {
        buff[counter - 1] = "0123456789ABCDEF"[value % base];
      } else {
        buff[counter - 1] = "0123456789abcdef"[value % base];
      }
      value /= base;
    }
  }
}

void ParsePointer(Flags *property, char *buff, va_list *va) {
  unsigned int value = va_arg(*va, unsigned int);
  property->specifier = 'x';
  property->octotorp = '#';

  UnsToString(property, value, buff, 16);
  if (property->precision_set) {
    IntPrecision(property, buff);
  }
  if (property->width) {
    IntWidth(property, buff);
  }
}

void ParseOctal(Flags *property, char *buff, va_list *va) {
  long long unsigned int value = va_arg(*va, long long unsigned int);

  if (property->length == 0) {
    value = (unsigned int)value;
  } else if (property->length == 'h') {
    value = (short unsigned int)value;
  } else if (property->length == 'l') {
    value = (long unsigned int)value;
  }

  UnsToString(property, value, buff, 8);
  if (property->precision_set) {
    IntPrecision(property, buff);
  }
  if (property->width) {
    IntWidth(property, buff);
  }
}

void ParseHex(Flags *property, char *buff, va_list *va) {
  long long unsigned int value = va_arg(*va, long long unsigned int);

  if (property->length == 0) {
    value = (unsigned int)value;
  } else if (property->length == 'h') {
    value = (short unsigned int)value;
  } else if (property->length == 'l') {
    value = (long unsigned int)value;
  }

  UnsToString(property, value, buff, 16);
  if (property->precision_set) {
    IntPrecision(property, buff);
  }
  if (property->width) {
    IntWidth(property, buff);
  }
}