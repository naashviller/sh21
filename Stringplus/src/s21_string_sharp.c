#include "s21_string_sharp.h"

void *alloc_memory(s21_size_t n) {
  char *buf = (char *)malloc(n);
  if (buf != s21_NULL) {
    s21_memset(buf, '\0', n);
  }

  return buf;
}

void *s21_to_upper(const char *str) {
  char *result = s21_NULL;

  if (str != s21_NULL) {
    s21_size_t length = s21_strlen(str);
    result = alloc_memory(length + 1);

    if (result != s21_NULL) {
      char *p = result;
      for (; *str; str++, p++) {
        if (*str > 96 && *str < 123) {
          *p = *str - 32;
        } else {
          *p = *str;
        }
      }
      *p = '\0';
    }
  }

  return result;
}

void *s21_to_lower(const char *str) {
  char *result = s21_NULL;

  if (str != s21_NULL) {
    s21_size_t length = s21_strlen(str);
    result = alloc_memory(length + 1);

    if (result != s21_NULL) {
      char *p = result;
      for (; *str; str++, p++) {
        if (*str > 64 && *str < 91) {
          *p = *str + 32;
        } else {
          *p = *str;
        }
      }
      *p = '\0';
    }
  }

  return result;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = s21_NULL;
  s21_size_t length2 = src ? s21_strlen(src) : 0;

  if (start_index <= length2) {
    if (str != s21_NULL && src != s21_NULL) {
      s21_size_t length1 = str ? s21_strlen(src) : 0;
      result = alloc_memory(length1 + length2 + 1);

      if (result != s21_NULL) {
        char *p = result;
        for (; *src && start_index; src++, p++, start_index--) {
          *p = *src;
        }
        for (; *str; str++, p++) {
          *p = *str;
        }
        for (; *src; src++, p++) {
          *p = *src;
        }
        *p = '\0';
      }
    }
  }

  return result;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *l_result = s21_NULL;
  char *r_result = s21_NULL;

  if (trim_chars == s21_NULL) {
    trim_chars = " \t\n\v";
  }
  if (src != s21_NULL) {
    s21_size_t length = s21_strlen(src);
    l_result = alloc_memory(length);
    if (l_result != s21_NULL) {
      int counter = 0;
      counter = s21_ltrim(l_result, src, trim_chars);
      r_result = alloc_memory(counter + 1);
      if (r_result != s21_NULL) {
        s21_rtrim(l_result, r_result, trim_chars, counter);
      }
      free(l_result);
    }
  }

  return r_result;
}

int s21_ltrim(char *l_result, const char *src, const char *trim_chars) {
  int counter = 0;
  char *p = l_result;
  bool flag1 = true;

  for (; *src; src++) {
    bool flag = true;
    char *p2 = (char *)trim_chars;
    for (; *p2; p2++) {
      if (*src == *p2) flag = false;
    }
    if (flag) flag1 = false;
    if (!flag1) {
      *p = *src;
      p++;
      counter++;
    }
  }

  return counter;
}

void s21_rtrim(char *l_result, char *r_result, const char *trim_chars,
               int counter) {
  bool flag2 = true;

  for (; counter >= 0; counter--) {
    bool flag = true;
    char *p2 = (char *)trim_chars;
    for (; *p2; p2++) {
      if (l_result[counter] == *p2 || l_result[counter] == '\0') flag = false;
    }
    if (flag) flag2 = false;
    if (!flag2)
      r_result[counter] = l_result[counter];
    else
      r_result[counter] = '\0';
  }
}