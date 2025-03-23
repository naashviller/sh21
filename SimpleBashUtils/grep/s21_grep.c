#include "s21_grep.h"

#include "grep_flags.h"

int main(int argc, char *argv[]) {
  bool exit_error = false;

  Flags entity = GrepFlags(&exit_error, argc, argv);
  if (!exit_error) {
    OpenFile(&exit_error, argc, argv, entity);
  }
  free(entity.pattern);
  return 0;
}

Flags GrepFlags(bool *exit_error, int argc, char *argv[]) {
  int flag = getopt_long(argc, argv, "ivclnhsoe:f:", 0, 0);
  Flags entity = {NULL,  0,     0,     false, false, false,
                  false, false, false, 0,     false};
  entity.pattern = MallocMemory(exit_error, 2);
  if (!*exit_error) {
    entity.pattern[0] = '\\';
    entity.pattern[1] = '\0';
    size_t pattern_size = 0;
    for (; flag != -1;
         flag = getopt_long(argc, argv, "ivclnhsoe:f:", 0,
                            0)) {  //: значит что обяз аргумент должен быть
      if (!*exit_error) {
        if (flag == 'e') {
          entity.pattern = GrepPattern(exit_error, entity.pattern,
                                       &pattern_size, optarg, strlen(optarg));
          entity.ef_flag |= REG_EXTENDED;
        } else if (flag == 'l') {  //выдает файлы, где есть то что мы ищем
          entity.flagL = true;
        } else if (flag == 'n') {
          entity.flagN = true;
        } else if (flag == 'h') {
          entity.flagH = true;
        } else if (flag == 'i') {  //игнор регистра
          entity.flagI |= REG_ICASE;
        } else if (flag == 'v') {  //выдает все строки кроме тех, что содержат
                                   //эту регулярку
          entity.flagV = true;
        } else if (flag ==
                   'c') {  //выдает кол-во строк, кот-е содержат этот образец
          entity.flagC = true;
        } else if (flag == 's') {
          entity.flagS = true;
        } else if (flag == 'f') {  //читаем регулярки с файла/лов
          entity.pattern = OpenPatternFile(exit_error, entity.pattern,
                                           &pattern_size, optarg);
          entity.ef_flag |= REG_EXTENDED;
        } else if (flag == 'o') {
          entity.flagO = true;
        }
      }
    }
    if (pattern_size) {
      entity.size = pattern_size;
    }
  }

  return entity;
}

char *OpenPatternFile(bool *exit_error, char *pattern, size_t *pattern_size,
                      char *file_name) {
  FILE *data;
  char *line = 0;
  size_t length = 0;

  data = fopen(file_name, "rb");
  if (data != NULL) {
    int len = 0;
    while ((len = getline(&line, &length, data)) > 0) {
      if (line[len - 1] == '\n') {
        line[len - 1] = '\0';
        len -= 1;
      }
      pattern = GrepPattern(exit_error, pattern, pattern_size, line, len);
    }
    free(line);
    fclose(data);
  } else {
    fprintf(stderr, "s21_grep: %s: No such file or directory\n", file_name);
    *exit_error = true;
  }

  return pattern;
}

char *GrepPattern(bool *exit_error, char *pattern, size_t *pattern_size,
                  char *expression, size_t arg_size) {
  pattern = AllocateMemory(exit_error, pattern, *pattern_size + arg_size + 4);
  if (!*exit_error) {
    pattern[*pattern_size] = '|';
    pattern[*pattern_size + 1] = '(';
    memcpy(pattern + *pattern_size + 2, expression, arg_size);
    *pattern_size += arg_size + 2;
    pattern[*pattern_size] = ')';
    pattern[*pattern_size + 1] = '\0';
    *pattern_size += 1;
  }
  return pattern;
}

void *AllocateMemory(bool *exit_error, void *block, size_t size) {
  void *temp;
  temp = realloc(block, size);
  if (temp == NULL) {
    *exit_error = true;
  }
  return temp;
}

void *MallocMemory(bool *exit_error, size_t size) {
  void *temp;
  temp = malloc(size);
  if (temp == NULL) {
    *exit_error = true;
  }
  return temp;
}

void OpenFile(bool *exit_error, int argc, char *argv[],
              Flags entity) {  //комп рег + чтен файлика
  char **end = &argv[argc];
  regex_t rx;

  if (argv[optind] == NULL) {  //если после флагов в ком строке ничего нет, а
                               //должно быть выраж кот ищем
    fprintf(stderr,
            "usage: grep [-hilfnosv] [-e pattern] [-f file] [pattern] [file "
            "...]\n");
  } else {
    int file_counter = 0;
    if (entity.size == 0) {  //разм динам строки, если  0 - обычное рег выр
      if (regcomp(&rx, argv[optind],
                  entity.flagI)) {  //если выраж не скомпил то вернетеся не 0 и
                                    //должна быть ошибка
        fprintf(stderr, "regex error: pattern not compiled");
        *exit_error = true;
      }
      file_counter =
          end - &argv[optind + 1];  //посл значение минус на кот остановились
    } else {
      if (regcomp(&rx, entity.pattern + 1, entity.ef_flag)) {
        fprintf(stderr, "regex error: pattern not compiled");
        *exit_error = true;
      }
      file_counter = end - &argv[optind];
    }
    if (!*exit_error) {
      if (file_counter == 0) {
        ReadFile(stdin, "", entity, &rx, 1);
      }
      for (char **filename = (entity.size ? &argv[optind] : &argv[optind + 1]);
           filename != end; ++filename) {
        FILE *data;
        data = fopen(*filename, "rb");
        if (data != NULL) {
          ReadFile(data, *filename, entity, &rx, file_counter);
          fclose(data);
        } else if (!entity.flagS) {
          fprintf(stderr, "s21_grep: %s: No such file or directory\n",
                  *filename);
        }
      }
      regfree(&rx);
    }
  }
}

void ReadFile(FILE *data, char *filename, Flags entity, regex_t *rx,
              int file_counter) {
  int str_counter = 0;
  int word_counter = 0;
  char *line = 0;
  size_t length = 0;
  regmatch_t match;

  while (getline(&line, &length, data) > 0) {
    ++str_counter;
    if (entity.flagV) {
      if ((regexec(rx, line, 1, &match, 0))) {
        ++word_counter;
        if (!entity.flagC && !entity.flagL) {
          GrepNFlag(filename, entity, str_counter, file_counter, line);
        }
      }
    } else {
      if (!(regexec(rx, line, 1, &match, 0))) {
        ++word_counter;
        if (!entity.flagC && !entity.flagL) {
          if (entity.flagO) {
            GrepOFlag(filename, entity, str_counter, file_counter, line, rx,
                      match);
          } else {
            GrepNFlag(filename, entity, str_counter, file_counter, line);
          }
        }
      }
    }
  }
  if ((entity.flagC || entity.flagL)) {
    GrepCLFlag(filename, entity, file_counter, word_counter);
  }
  free(line);
}
