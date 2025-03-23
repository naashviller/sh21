#include "grep_flags.h"

#include <stdio.h>

#include "s21_grep.h"

void GrepCLFlag(char *filename, Flags entity, int file_counter,
                int word_counter) {
  if (entity.flagC && entity.flagL && word_counter) {
    if ((file_counter > 1 && !entity.flagH)) {
      printf("%s:%d\n", filename, 1);
      printf("%s\n", filename);
    } else {
      printf("%d\n", 1);
      printf("%s\n", filename);
    }
  } else if (entity.flagC) {
    if ((file_counter > 1 && !entity.flagH)) {
      printf("%s:%d\n", filename, word_counter);
    } else {
      printf("%d\n", word_counter);
    }
  } else if (entity.flagL && word_counter) {
    printf("%s\n", filename);
  }
}

void GrepOFlag(char *filename, Flags entity, int str_counter, int file_counter,
               char *line, regex_t *rx, regmatch_t match) {
  if (entity.flagN && file_counter > 1 && !entity.flagH) {
    printf("%s:%d:%.*s\n", filename, str_counter,
           (int)(match.rm_eo - match.rm_so),
           line + match.rm_so);  // 3 аргумент это кол-во эл в структуре мэтч
  } else if (entity.flagN) {
    printf("%d:%.*s\n", str_counter, (int)(match.rm_eo - match.rm_so),
           line + match.rm_so);
  } else if (file_counter > 1 && !entity.flagH) {
    printf("%s:%.*s\n", filename, (int)(match.rm_eo - match.rm_so),
           line + match.rm_so);
  } else {
    printf("%.*s\n", (int)(match.rm_eo - match.rm_so), line + match.rm_so);
  }
  char *contin = line + match.rm_eo;
  while (!regexec(rx, contin, 1, &match, 0)) {
    if (entity.flagN && file_counter > 1 && !entity.flagH) {
      printf("%s:%d:%.*s\n", filename, str_counter,
             (int)(match.rm_eo - match.rm_so), contin + match.rm_so);
    } else if (entity.flagN) {
      printf("%d:%.*s\n", str_counter, (int)(match.rm_eo - match.rm_so),
             contin + match.rm_so);
    } else if (file_counter > 1 && !entity.flagH) {
      printf("%s:%.*s\n", filename, (int)(match.rm_eo - match.rm_so),
             contin + match.rm_so);
    } else {
      printf("%.*s\n", (int)(match.rm_eo - match.rm_so), contin + match.rm_so);
    }
    contin += match.rm_eo;
  }
}

void GrepNFlag(char *filename, Flags entity, int str_counter, int file_counter,
               char *line) {
  if (entity.flagN && (file_counter > 1 && !entity.flagH)) {
    printf("%s:%d:%s", filename, str_counter, line);
  } else if (entity.flagN) {
    printf("%d:%s", str_counter, line);
  } else if ((file_counter > 1 && !entity.flagH)) {
    printf("%s:%s", filename, line);
  } else {
    printf("%s", line);
  }
}