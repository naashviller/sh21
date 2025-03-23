#include "s21_grep.h"

#ifndef GREP_FLAGS_H
#define GREP_FLAGS_H

void GrepCLFlag(char *filename, Flags entity, int file_counter,
                int word_counter);
void GrepNFlag(char *filename, Flags entity, int str_counter, int file_counter,
               char *line);
void GrepOFlag(char *filename, Flags entity, int str_counter, int file_counter,
               char *line, regex_t *rx, regmatch_t match);

#endif
