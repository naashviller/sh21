#include "s21_string_fuction.h"

s21_size_t s21_strlen(const char *s) {
  s21_size_t length = 0;

  for (; s[length]; length++)
    ;
  return length;
}

s21_size_t s21_strspn(const char *s1, const char *s2) {
  s21_size_t length = 0;
  bool flag = true;

  for (; s1[length] && flag;) {
    const char *p;
    for (p = s2; *p && *p != s1[length]; p++)
      ;
    if (!*p) {
      flag = false;
    } else {
      length++;
    }
  }

  return length;
}

s21_size_t s21_strcspn(const char *s1, const char *s2) {
  s21_size_t length = 0;
  bool flag = true;

  for (; s1[length] && flag;) {
    const char *p = s2;
    for (; *p && *p != s1[length]; p++)
      ;
    if (*p) {
      flag = false;
    } else {
      length++;
    }
  }

  return length;
}

int s21_strcmp(const char *s1, const char *s2) {
  for (; *s1 && *s1 == *s2; s1++, s2++)
    ;
  return *s1 - *s2;
}

int s21_strncmp(const char *s1, const char *s2, s21_size_t n) {
  int res = 0;

  if (n == 0) {
    res = 0;
  } else {
    for (; (n - 1) && *s1 && *s1 == *s2; s1++, s2++, n--)
      ;
    res = *s1 - *s2;
  }

  return res;
}

int s21_memcmp(const void *s1, const void *s2, s21_size_t n) {
  const unsigned char *p1 = s1;
  const unsigned char *p2 = s2;
  int res = 0;

  if (s1 == s2) {
    return res;
  }
  while (n != 0) {
    if (*p1 != *p2) {
      res = (*p1 > *p2) ? 1 : -1;
      n = 0;
    } else {
      n--;
      p1++;
      p2++;
    }
  }

  return res;
}

char *s21_strcpy(char *restrict s1, const char *restrict s2) {
  char *p = s1;

  if (s1 != s21_NULL) {
    for (; *s2; s1++, s2++) {
      *s1 = *s2;
    }
    *s1 = '\0';
  }

  return p;
}

char *s21_strncpy(char *restrict s1, const char *restrict s2, s21_size_t n) {
  char *p = s1;
  s21_size_t temp = 0;

  if (s1 != s21_NULL) {
    for (; temp < n && *s2; temp++, s1++, s2++) {
      *s1 = *s2;
    }
    if (temp < n) {
      *s1 = '\0';
    }
  }

  return p;
}

void *s21_memcpy(void *dst, const char *src, s21_size_t n) {
  char *pDst = (char *)dst;
  const char *pSrc = (const char *)src;

  if (pDst != s21_NULL && pSrc != s21_NULL) {
    while (n != 0) {
      *(pDst++) = *(pSrc++);
      n--;
    }
  }

  return dst;
}

void *s21_memset(void *b, int c, s21_size_t n) {
  unsigned char *p = (unsigned char *)b;

  if (p != s21_NULL) {
    while (n != 0) {
      *p++ = (unsigned char)c;
      n--;
    }
  }

  return b;
}

void *s21_memchr(const void *s, int c, s21_size_t n) {
  unsigned char *p = (unsigned char *)s;
  unsigned char *res = s21_NULL;

  if (p != s21_NULL) {
    while (n != 0) {
      if (*p != (unsigned char)c) {
        p++;
        n--;
      } else {
        res = p;
        n = 0;
      }
    }
  }

  return res;
}

char *s21_strchr(const char *s, int c) {
  bool flag = true;
  char *p = (char *)s;

  for (; *p && flag;) {
    if (*p == c) {
      flag = false;
    } else {
      p++;
    }
  }
  if (!*p && c != '\0') {
    p = s21_NULL;
  }

  return p;
}

char *s21_strpbrk(const char *s1, const char *s2) {
  bool flag = true;
  char *p1 = (char *)s1;

  for (; *p1 && flag;) {
    const char *p2 = s2;
    for (; *p2 && *p1 != *p2; p2++)
      ;
    if (*p2) {
      flag = false;
    } else {
      p1++;
    }
  }
  if (!*p1) {
    p1 = s21_NULL;
  }

  return p1;
}

char *s21_strrchr(const char *s, int c) {
  bool flag = true;
  s21_size_t length = s21_strlen(s);
  char *p = (char *)s;

  for (s21_size_t temp = 1; temp != length && flag;) {
    if (s[length] == c) {
      flag = false;
    } else {
      length--;
    }
  }
  if (length == 1) {
    p = s21_NULL;
  } else {
    p += length;
  }

  return p;
}

char *s21_strstr(const char *s1, const char *s2) {
  bool flag = true;
  s21_size_t length = s21_strlen(s2);
  char *p1 = (char *)s1;

  if (length) {
    for (; *p1 && flag;) {
      if (!s21_strncmp(p1, s2, length)) {
        flag = false;
      } else {
        p1++;
      }
    }
    if (!*p1) {
      p1 = s21_NULL;
    }
  }

  return p1;
}

char *s21_strtok(char *restrict s1, const char *restrict s2) {
  bool flag = true;
  char *p1 = s21_NULL;
  static char *r_value;

  if (s1 == s21_NULL) {
    p1 = r_value;
  } else {
    p1 = s1;
  }
  if (p1 != s21_NULL) {
    for (; *p1 && flag;) {
      const char *p2 = s2;
      for (; *p2 && *p1 != *p2; p2++)
        ;
      if (!*p2) {
        flag = false;
      } else {
        p1++;
      }
    }
    if (!*p1) {
      p1 = s21_NULL;
    } else {
      char *p3 = p1;
      bool flag1 = true;
      for (; *p3 && flag1; p3++) {
        const char *p2 = s2;
        for (; *p2 && *p3 != *p2; p2++)
          ;
        if (*p2) {
          *p3 = '\0';
          flag1 = false;
        }
      }
      if (!*p3) {
        r_value = s21_NULL;
      } else {
        r_value = p3;
      }
    }
  }

  return p1;
}

char *s21_strerror(int errnum) {
  char *result = s21_NULL;

  if (errnum < 0 || errnum > ERRLIST - 1) {
    s21_sprintf(buff, "%s %d", errormassege[0], errnum);
    result = buff;
  } else {
    result = (char *)s21_errorlist[errnum];
  }

  return result;
}

char *s21_strcat(char *restrict s1, const char *restrict s2) {
  s21_size_t length = s21_strlen(s1);
  char *p1 = s1 + length;
  char *p2 = (char *)s2;

  for (; *p2; p1++, p2++) {
    *p1 = *p2;
  }
  *p1 = '\0';

  return s1;
}

char *s21_strncat(char *restrict s1, const char *restrict s2, s21_size_t n) {
  s21_size_t length = s21_strlen(s1);
  char *p1 = s1 + length;
  char *p2 = (char *)s2;

  for (; n && *p2; p1++, p2++, n--) {
    *p1 = *p2;
  }
  *p1 = '\0';

  return s1;
}

long s21_atoi(const char s[]) {
  long num = 0;
  int i = 0;
  int sign = 1;

  for (; s[i] == ' ' || s[i] == '\n' || s[i] == '\t'; i++)
    ;
  if (s[i] == '+' || s[i] == '-') {
    if (s[i] == '-') {
      sign = -1;
    }
    i++;
  }
  for (; s[i] && (s[i] > 47 && s[i] < 58); i++) {
    num = num * 10 + (s[i] - 48);
  }

  return sign * num;
}