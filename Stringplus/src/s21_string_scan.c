#include "s21_string_scan.h"

#include "s21_string.h"

int s21_sscanf(const char* str, const char* format, ...) {
  int result = 0;
  va_list input;
  va_start(input, format);

  // создаем первую структуру
  struct List* ptrList = (struct List*)calloc(1, sizeof(struct List));
  initList(ptrList);

  if (ptrList != s21_NULL) {
    result = analyzeFormatS(ptrList, format, str, input);
  }
  va_end(input);
  return result;
}

int analyzeFormatS(struct List* ptrList, const char* format,
                   const char* exhaust, va_list input) {
  int result_count = 0, flag = 0, indexBuffer = 0, formatIndex = 0;
  char example = '%';
  if (exhaust != s21_NULL) {
    for (int i = 0; i < (int)s21_strlen(format); i++) {
      if ((int)(*(format + i)) == (int)(example) && flag == 0) {
        flag = 1;
        formatIndex = i;
      } else if ((int)(*(format + i)) != (int)(example) && flag == 1) {
        ptrList->indicator = 0;
        int result = 0;
        result = fillListS(ptrList, (format + i));
        if (indexBuffer == 0) {
          indexBuffer = fillStr(
              ptrList, &(ptrList->sscanf_str), formatIndex, exhaust,
              (format +
               formatIndex));  // запишем в sscanf(в структуру) строчку(слово до
                               // пробела или '\t' или '\n')
        } else if (indexBuffer > 0)
          indexBuffer = fillStr(ptrList, &(ptrList->sscanf_str), indexBuffer,
                                exhaust, (format + formatIndex));

        i = i + ptrList->strIndex;
        if (result == 1) {
          flag = 0;  // значит в строке формат есть корректный ' %..."spec" '
        } else if (result == -1)
          break;
        if (ptrList->width > 0 &&
            ptrList->width < (int)s21_strlen(ptrList->sscanf_str))
          indexBuffer =
              indexBuffer -
              ((int)s21_strlen(ptrList->sscanf_str) - ptrList->width) -
              skipSymbols(exhaust, indexBuffer);
        else if (ptrList->width / (-3) > 1)
          indexBuffer = indexBuffer - (int)s21_strlen(ptrList->sscanf_str) +
                        ptrList->width / (-3);
        fillVar(ptrList, input, &indexBuffer);
        result_count = result_count + ptrList->counter;
        destroyList(ptrList);
        ptrList = (struct List*)calloc(1, sizeof(struct List));
        initList(ptrList);

      } else if ((int)(*(format + i)) == (int)(example) && flag == 1) {
        break;
      } else if ((int)(*(format + i)) != (int)(example) && flag == 0) {
        if ((int)(*(format + i)) == (int)(*(exhaust + indexBuffer)))  // гуд
          indexBuffer++;
      }
    }
  }
  destroyList(ptrList);
  return result_count;
}

int fillVar(struct List* ptrList, va_list input, int* indexBuffer) {
  *indexBuffer = *indexBuffer - (int)s21_strlen(ptrList->sscanf_str) + 1;
  if (ptrList->width != -1) {
    ptrList->counter++;
    if (ptrList->specifier == 'c')
      specifierC(ptrList, input);

    else if (ptrList->specifier != 'c') {
      *indexBuffer = *indexBuffer + (int)s21_strlen(ptrList->sscanf_str) - 1;
      if (ptrList->specifier == 'd' && ptrList->width / (-3) <= 1)
        specifierD(ptrList, input);
      else if (ptrList->specifier == 'i' && ptrList->width / (-3) <= 1)
        specifierI(ptrList, input);
      else if (ptrList->specifier == 'e' || ptrList->specifier == 'E' ||
               ptrList->specifier == 'f' || ptrList->specifier == 'g' ||
               ptrList->specifier == 'G')
        specifierEeFgG(ptrList, input);
      else if (ptrList->specifier == 'o' || ptrList->specifier == 'u' ||
               ptrList->specifier == 'x' || ptrList->specifier == 'X')
        specifierOuXx(ptrList, input);
      else if (ptrList->specifier == 's')
        specifierS(ptrList, input);
      else if (ptrList->specifier == 'p')
        specifierP(ptrList, input);
      else if (ptrList->specifier == 'n') {
        *va_arg(input, int*) =
            *indexBuffer - (int)s21_strlen(ptrList->sscanf_str);
        ptrList->counter--;
      } else
        ptrList->counter--;
    }
  }
  return 0;
}

void specifierC(struct List* ptrList, va_list input) {
  char* example = "l";
  if (s21_strpbrk(example, ptrList->length) != s21_NULL)  // т.е wchar_t
    s21_memcpy(va_arg(input, wchar_t*), ptrList->sscanf_str, 1);
  else
    s21_memcpy(va_arg(input, char*), ptrList->sscanf_str, 1);
}

void specifierD(struct List* ptrList, va_list input) {
  char* example1 = "h";
  char* example2 = "l";
  if (s21_strpbrk(example1, ptrList->length) != s21_NULL)  // h
    *va_arg(input, short int*) = intTranslation(ptrList);
  else if (s21_strpbrk(example2, ptrList->length) != s21_NULL)  // l
    *va_arg(input, long int*) = intTranslation(ptrList);
  else
    *va_arg(input, int*) = intTranslation(ptrList);
}

void specifierI(struct List* ptrList, va_list input) {
  // 16, 8, 10 - CC
  char* example1 = "h";
  char* example2 = "l";
  int i = 0;
  if (ptrList->sscanf_str[0] == '-' || ptrList->sscanf_str[0] == '+') i = 1;

  if (ptrList->sscanf_str[i] == '0' && (ptrList->sscanf_str[i + 1] == 'x' ||
                                        ptrList->sscanf_str[i + 1] == 'X')) {
    if (s21_strpbrk(example1, ptrList->length) != s21_NULL)  // h
      *va_arg(input, short int*) = numSystemConvert(ptrList, 16);
    else if (s21_strpbrk(example2, ptrList->length) != s21_NULL)  // l
      *va_arg(input, long int*) = numSystemConvert(ptrList, 16);
    else
      *va_arg(input, int*) = numSystemConvert(ptrList, 16);
  } else if (ptrList->sscanf_str[i] == '0' &&
             ptrList->sscanf_str[i + 1] != 'x' &&
             ptrList->sscanf_str[i + 1] != 'X') {
    if (s21_strpbrk(example1, ptrList->length) != s21_NULL)  // h
      *va_arg(input, short int*) = numSystemConvert(ptrList, 8);
    else if (s21_strpbrk(example2, ptrList->length) != s21_NULL)  // l
      *va_arg(input, long int*) = numSystemConvert(ptrList, 8);
    else
      *va_arg(input, int*) = numSystemConvert(ptrList, 8);
  } else {
    if (s21_strpbrk(example1, ptrList->length) != s21_NULL)  // h
      *va_arg(input, short int*) = numSystemConvert(ptrList, 10);
    else if (s21_strpbrk(example2, ptrList->length) != s21_NULL)  // l
      *va_arg(input, long int*) = numSystemConvert(ptrList, 10);
    else
      *va_arg(input, int*) = numSystemConvert(ptrList, 10);
  }
}

void specifierEeFgG(struct List* ptrList, va_list input) {
  char* example = "L";

  if (s21_strpbrk(example, ptrList->length) != s21_NULL)  // L
  {
    *va_arg(input, long double*) = convertLongNotation(ptrList);
  } else {
    *va_arg(input, float*) = (float)convertLongNotation(ptrList);
  }
}

void specifierOuXx(struct List* ptrList, va_list input) {
  char* example1 = "h";
  char* example2 = "l";
  if (ptrList->specifier == 'o') {
    if (s21_strpbrk(example1, ptrList->length) != s21_NULL)  // h
      *va_arg(input, unsigned short int*) = numSystemConvert(ptrList, 8);
    else if (s21_strpbrk(example2, ptrList->length) != s21_NULL)  // l
      *va_arg(input, unsigned long int*) = numSystemConvert(ptrList, 8);
    else
      *va_arg(input, unsigned int*) = numSystemConvert(ptrList, 8);
  } else if (ptrList->specifier == 'u') {
    if (s21_strpbrk(example1, ptrList->length) != s21_NULL)  // h
      *va_arg(input, unsigned short int*) = numSystemConvert(ptrList, 10);
    else if (s21_strpbrk(example2, ptrList->length) != s21_NULL)  // l
      *va_arg(input, unsigned long int*) = numSystemConvert(ptrList, 10);
    else
      *va_arg(input, unsigned int*) = numSystemConvert(ptrList, 10);
  } else if (ptrList->specifier == 'x' || ptrList->specifier == 'X') {
    if (s21_strpbrk(example1, ptrList->length) != s21_NULL)  // h
      *va_arg(input, unsigned short int*) = numSystemConvert(ptrList, 16);
    else if (s21_strpbrk(example2, ptrList->length) != s21_NULL)  // l
      *va_arg(input, unsigned long int*) = numSystemConvert(ptrList, 16);
    else
      *va_arg(input, unsigned int*) = numSystemConvert(ptrList, 16);
  }
}

void specifierS(struct List* ptrList, va_list input) {
  char* example1 = "l";
  int slen = s21_strlen(ptrList->sscanf_str);
  if (ptrList->width > 0 && ptrList->width < slen) slen = ptrList->width;
  if (s21_strpbrk(example1, ptrList->length) != s21_NULL)  // l
  {
    s21_memcpy(va_arg(input, wchar_t*), ptrList->sscanf_str, slen + 1);
  } else {
    s21_memcpy(va_arg(input, char*), ptrList->sscanf_str,
               slen + 1);  // +1 т.к еще нужен '\0'
  }
}

void specifierP(struct List* ptrList, va_list input) {
  unsigned long int* ptr = va_arg(input, void*);
  unsigned long int a = 0x0;

  int rang = (int)s21_strlen(ptrList->sscanf_str) - 1;
  if (ptrList->width > 0 && ptrList->width < rang) rang = ptrList->width - 1;

  long int result = 0;
  long int transform = 0;
  long int calculate = 0;
  int j = 0;
  int k = 0;
  if (k + 1 >= (int)s21_strlen(ptrList->sscanf_str))  // во избежании сеги
  {
    k = 0;
    rang = -1;
  }

  if (ptrList->sscanf_str[k] == '0' &&
      (ptrList->sscanf_str[k + 1] == 'x' || ptrList->sscanf_str[k + 1] == 'X'))
    j = 2;
  else if (ptrList->sscanf_str[k] == '0' && ptrList->sscanf_str[k + 1] != 'x' &&
           ptrList->sscanf_str[k + 1] != 'X')
    j = 1;

  for (int i = rang, w = 0; i >= j; i--) {
    transform = systemSymbolCheck(ptrList->sscanf_str[i]);
    if (transform == 0) transform = (int)((ptrList->sscanf_str)[i] - '0');

    if (transform != -1) {
      calculate = transform * pow(16, w);
      result = result + calculate;
      w++;
    }
  }
  *ptr = a + result;
}

s21_size_t numSystemConvert(struct List* ptrList, int index) {
  int rang = (int)s21_strlen(ptrList->sscanf_str) - 1;
  if (ptrList->width > 0 && ptrList->width < rang) rang = ptrList->width - 1;
  int sign = 1;  // знак числа
  if (ptrList->sscanf_str[0] == '-') sign = -1;
  int transform = 0;
  int calculate = 0;
  s21_size_t result = 0;
  int j = 0;
  int k = 0;
  if (ptrList->sscanf_str[0] == '-' || ptrList->sscanf_str[0] == '+') k = 1;
  if (k + 1 >= (int)s21_strlen(ptrList->sscanf_str))  // во избежании сеги
  {
    k = 0;
    rang = -1;
  }
  if (ptrList->sscanf_str[k] == '0' && (ptrList->sscanf_str[k + 1] == 'x' ||
                                        ptrList->sscanf_str[k + 1] == 'X')) {
    if (index == 16)
      j = 2;
    else  // ошибка
      rang = -1;
  } else if (ptrList->sscanf_str[k] == '0' &&
             ptrList->sscanf_str[k + 1] != 'x' &&
             ptrList->sscanf_str[k + 1] != 'X') {
    if (index == 8)
      j = 1;
    else if (index == 10)
      j = 0;
    else  // ошибка
      rang = -1;
  } else
    j = 0;

  for (int i = rang, w = 0; i >= j; i--) {
    transform = systemSymbolCheck(ptrList->sscanf_str[i]);
    if (transform == 0) transform = (int)((ptrList->sscanf_str)[i] - '0');
    if (transform != -1) {
      if ((index == 8 && transform > 7) || (index == 10 && transform > 9)) {
        break;
      } else {
        calculate = transform * pow(index, w);
        result = result + calculate;
        w++;
      }
    }
  }
  result = result * sign;
  return result;
}

int systemSymbolCheck(char sym) {
  const char* example = "0123456789ABCDEFabcdef";
  int transform = 0;
  if (sym == 'A' || sym == 'a')
    transform = 10;
  else if (sym == 'B' || sym == 'b')
    transform = 11;
  else if (sym == 'C' || sym == 'c')
    transform = 12;
  else if (sym == 'D' || sym == 'd')
    transform = 13;
  else if (sym == 'E' || sym == 'e')
    transform = 14;
  else if (sym == 'F' || sym == 'f')
    transform = 15;

  if (s21_strchr(example, (int)sym) == s21_NULL) transform = -1;

  return transform;
}

s21_size_t intTranslation(struct List* ptrList) {
  int res_sign = 1;
  s21_size_t result = 0;
  int run = 0;
  if (ptrList->width > 0)
    run = ptrList->width;
  else
    run = (int)s21_strlen(ptrList->sscanf_str);

  if (ptrList->width > (int)s21_strlen(ptrList->sscanf_str))
    run = s21_strlen(ptrList->sscanf_str);

  int i = 0;
  if (ptrList->sscanf_str[0] == '-' || ptrList->sscanf_str[0] == '+') {
    i = 1;
    if (ptrList->sscanf_str[0] == '-') res_sign = -1;
  }

  for (; i < run; i++)
    result =
        (int)((ptrList->sscanf_str)[i] - '0') * pow(10, (run - i - 1)) + result;

  result = result * res_sign;
  return result;
}

int skipSymbols(const char* exhaust, int index) {
  int res = 0;
  while (*(exhaust + index - 1 - res) == '\n' ||
         *(exhaust + index - 1 - res) == '\t' ||
         *(exhaust + index - 1 - res) == ' ')
    res++;

  return res;
}

long double convertLongNotation(struct List* ptrList) {
  long double result = 0;
  char* example1 = "0123456789";
  long double res_sign = 1;  // знак числа
  if (ptrList->sscanf_str[0] == '-') res_sign = -1;
  long double exp_sign = 1;  // знак экспоненты по умолчанию '+'
  int degree = 0;
  int flag = 0;
  int count_num = 0;
  int slen = (int)s21_strlen(ptrList->sscanf_str);
  if (ptrList->width > 0 && ptrList->width < slen) slen = ptrList->width;
  long double result1 = 0;
  for (int i = 0; i < slen; i++) {
    if (flag == 1) count_num++;
    if (s21_strchr(example1, (int)(ptrList->sscanf_str[i])) != s21_NULL) {
      if (flag == 1)
        result1 =
            result1 + ((ptrList->sscanf_str[i]) - '0') * pow(10, -count_num);
      else
        result1 = result1 * 10 + ((ptrList->sscanf_str[i]) - '0');
    } else if (ptrList->sscanf_str[i] == '.')
      flag = 1;
    else if (ptrList->sscanf_str[i] == 'e' || ptrList->sscanf_str[i] == 'E') {
      int j = i;
      for (; j < slen; j++) {
        if (ptrList->sscanf_str[j] == '-')
          exp_sign = -1;

        else if (s21_strchr(example1, (int)(ptrList->sscanf_str[j])) !=
                 s21_NULL)
          degree = degree * 10 + ((int)(ptrList->sscanf_str[j]) - '0');

        else if (ptrList->sscanf_str[i] != 'e' && ptrList->sscanf_str[i] != 'E')
          break;
      }
      i = j;
    } else if (ptrList->sscanf_str[0] != '-' && ptrList->sscanf_str[0] != '+')
      break;
  }
  result = res_sign * result1 * pow(10.0, exp_sign * degree);
  return result;
}

int fillStr(struct List* ptrList, char** sscanf_str, int index,
            const char* exhaust, const char* symbol) {
  if (ptrList->specifier == 'c') {
    if ((index != 0 && (int)(*(symbol - 1)) != ' ' &&
         *(exhaust + index) == ' ') ||
        (index == 0 && *(exhaust + index) == ' ')) {
      if ((int)s21_strlen(*sscanf_str) >= 1) {
        char* copy = *sscanf_str;
        *sscanf_str =
            (char*)realloc(*sscanf_str, (int)s21_strlen(*sscanf_str) + 2);
        if (*sscanf_str != s21_NULL)
          s21_strncat(*sscanf_str, exhaust + index, 1);
        else {
          free(copy);
          copy = s21_NULL;
        }
      } else
        s21_strncat(*sscanf_str, exhaust + index, 1);
    }
  }

  while (*(exhaust + index) == '\n' || *(exhaust + index) == '\t' ||
         *(exhaust + index) == ' ')
    index++;
  while (*(exhaust + index) != '\n' && *(exhaust + index) != '\t' &&
         *(exhaust + index) != ' ' && index < (int)s21_strlen(exhaust)) {
    if ((int)s21_strlen(*sscanf_str) >= 1) {
      char* copy = *sscanf_str;
      *sscanf_str =
          (char*)realloc(*sscanf_str, (int)s21_strlen(*sscanf_str) + 2);
      if (*sscanf_str != s21_NULL)
        s21_strncat(*sscanf_str, exhaust + index, 1);
      else {
        free(copy);
        copy = s21_NULL;
        break;
      }
    } else
      s21_strncat(*sscanf_str, exhaust + index, 1);

    index++;
  }
  return index;
}

int fillListS(struct List* ptrList, const char* formatSym) {
  int res = 0;
  // проверка на ширину
  int j = 0;
  while (ptrList->indicator == 0 || ptrList->indicator == 1) {
    ptrList->indicator = checkWidthS(*(formatSym + j), &(ptrList->width));
    j++;
  }
  // if (ptrList->width == -1) j++;
  formatSym = formatSym + j - 1;  // j-1 НЕОТРИЦАТЕЛЬНО!!!

  // на длину
  int w = 0;
  while (ptrList->indicator == 2) {
    ptrList->indicator = checkLengthS(*(formatSym + w), &ptrList->length);
    w++;
  }
  formatSym = formatSym + w - 1;  // w-1 НЕОТРИЦАТЕЛЬНО!!!

  // на спецификатор
  if (ptrList->indicator == 3) {
    ptrList->indicator = checkSpecifierS(*formatSym, &(ptrList->specifier));
    if (ptrList->indicator == 1)
      res = 1;  // успешное заполнение структуры для какого-то одного '%'
    else
      res = -1;
  } else
    res = -1;

  ptrList->strIndex = j - 1 + w - 1;
  return res;
}

int checkWidthS(char symbol, int* width) {
  int out = 0;
  char* example = "*";
  if (width != s21_NULL) {
    if (((int)(symbol) >= 48 && (int)(symbol) <= 57) && *width != -1) {
      out = 1;
      if (*width > 0) {
        *width = *width * 10 + symbol - '0';
      } else if (*width == 0)
        *width = symbol - '0';
    }

    else if (((int)(symbol) >= 48 && (int)(symbol) <= 57) && *width < 0) {
      if (*width < -1) {
        *width = (*width * 10 + symbol - '0');
      } else if (*width == -1) {
        if ((symbol - '0') == 0)
          *width = -1;
        else
          *width = -3 * (symbol - '0');
      }
      out = 1;
    }

    else if (s21_strchr(example, (int)symbol) != s21_NULL) {
      *width = -1;
      out = 1;
    } else {
      if (*width == 0) *width = -3;
      out = 2;
    }
  }
  return out;
}

int checkLengthS(char symbol, char** length) {
  int out = 0;
  char* example = "hlL";
  if (*length != s21_NULL) {
    if (s21_strchr(example, (int)symbol) != s21_NULL &&
        (int)s21_strlen(*length) == 0) {
      out = 2;
      s21_strncpy(*length, &symbol, 1);
    } else
      out = 3;
  }
  return out;
}

int checkSpecifierS(char symbol, char* specifier) {
  int out = 0;
  char example[] = "cdieEfgGosuxXpn";
  if (specifier != s21_NULL) {
    if (s21_strchr(example, (int)symbol) != s21_NULL) {
      out = 1;
      *specifier = symbol;
    }
  }
  return out;
}
