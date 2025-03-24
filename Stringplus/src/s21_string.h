#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define s21_size_t unsigned long
#define s21_NULL (void *)0

s21_size_t s21_strlen(const char *s);
s21_size_t s21_strspn(const char *s1, const char *s2);
s21_size_t s21_strcspn(const char *s1, const char *s2);
int s21_strcmp(const char *s1, const char *s2);
int s21_strncmp(const char *s1, const char *s2, s21_size_t n);
int s21_memcmp(const void *s1, const void *s2, s21_size_t n);
char *s21_strcpy(char *restrict s1, const char *restrict s2);
char *s21_strncpy(char *restrict s1, const char *restrict s2, s21_size_t n);
void *s21_memcpy(void *dst, const char *src, s21_size_t n);
void *s21_memset(void *b, int c, s21_size_t n);
void *s21_memchr(const void *s, int c, s21_size_t n);
char *s21_strchr(const char *s, int c);
char *s21_strpbrk(const char *s1, const char *s2);
char *s21_strrchr(const char *s, int c);
char *s21_strstr(const char *s1, const char *s2);
char *s21_strtok(char *restrict s1, const char *restrict s2);
char *s21_strerror(int errnum);
char *s21_strcat(char *restrict s1, const char *restrict s2);
char *s21_strncat(char *restrict s1, const char *restrict s2, s21_size_t n);
long s21_atoi(const char s[]);
int s21_sprintf(char *restrict str, const char *restrict format, ...);
int s21_sscanf(const char *restrict str, const char *restrict format, ...);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

#endif