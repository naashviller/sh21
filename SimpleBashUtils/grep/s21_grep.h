#include <errno.h>
#include <getopt.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef S21_GREP_H
#define S21_GREP_H

typedef struct {
  char *pattern;
  size_t size;
  int flagI;
  bool flagV;
  bool flagC;
  bool flagL;
  bool flagN;
  bool flagH;
  bool flagS;
  int ef_flag;
  bool flagO;
} Flags;

Flags GrepFlags(bool *exit_error, int argc, char *argv[]);
void *AllocateMemory(bool *exit_error, void *block, size_t size);
void *MallocMemory(bool *exit_error, size_t size);
char *GrepPattern(bool *exit_error, char *pattern, size_t *pattern_size,
                  char *expression, size_t temp_size);
void OpenFile(bool *exit_error, int argc, char *argv[], Flags entity);
void ReadFile(FILE *data, char *filename, Flags entity, regex_t *rx,
              int file_counter);
char *OpenPatternFile(bool *exit_error, char *pattern, size_t *pattern_size,
                      char *file_name);

#endif
