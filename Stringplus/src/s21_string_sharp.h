#ifndef S21_STRING_SHARP_H
#define S21_STRING_SHARP_H

#include "s21_string.h"

void *alloc_memory(s21_size_t n);
int s21_ltrim(char *l_result, const char *src, const char *trim_chars);
void s21_rtrim(char *l_result, char *r_result, const char *trim_chars,
               int counter);

#endif