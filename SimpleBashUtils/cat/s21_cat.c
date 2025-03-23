#include "s21_cat.h"

#include "cat_flags.h"

int main(int argc, char *argv[]) {
  const char *table[256];

  Flags entity = CatFlags(argc, argv);
  CreateTable(table);

  if (entity.flagV) {
    FlagV(table);
  }
  if (entity.flagT) {
    FLagT(table);
  }
  if (entity.flagE) {
    FlagE(table);
  }

  FileOpen(argc, argv, table, entity);

  return 0;
}

Flags CatFlags(int argc, char *argv[]) {
  struct option longOption[] = {{"number-nonblank", 0, NULL, 'b'},
                                {"number", 0, NULL, 'n'},
                                {"squeeze-blank", 0, NULL, 's'},
                                {NULL, 0, NULL, 0}};
  int flag =
      getopt_long(argc, argv, "+beEnstTv", longOption,
                  NULL);  //+ говорит о том что сначала будут идти флаги а потом
                          //имя файла, после файла флаги идти не будут
  Flags entity = {false, false, false, false, false, false};
  for (; flag != -1;
       flag = getopt_long(argc, argv, "+beEnstTv", longOption, NULL)) {
    if (flag == 'e') {
      entity.flagE = true;
      entity.flagV = true;
    } else if (flag == 'E') {
      entity.flagE = true;
    } else if (flag == 't') {
      entity.flagT = true;
      entity.flagV = true;
    } else if (flag == 'T') {
      entity.flagT = true;
    } else if (flag == 'b') {
      entity.flagB = true;
    } else if (flag == 'n') {
      entity.flagN = true;
    } else if (flag == 's') {
      entity.flagS = true;
    } else if (flag == 'v') {
      entity.flagV = true;
    }
  }
  return entity;
}

void FileOpen(int argc, char *argv[], const char *table[static 256],
              Flags entity) {
  if (argv[optind] == NULL) {
    FileRead(entity, stdin, table);
  } else {
    for (char **file_name = &argv[optind]; file_name != &argv[argc];
         file_name++) {
      FILE *data = fopen(*file_name, "rb");
      if (data != NULL) {
        FileRead(entity, data, table);
        fclose(data);
      } else {
        fprintf(stderr, "s21_cat: %s: No such file or directory\n", *file_name);
      }
    }
  }
}

void FileRead(Flags entity, FILE *data, const char *table[static 256]) {
  bool empty_del = false;  //для отслеж пуст строк
  int word = 0;            //по 1 симв
  int lineCount = 0;
  int last_word = '\n';
  bool empty = false;  //отслеж пуст строк+нум строк

  while (fread(&word, 1, 1, data) > 0) {  //если нет сим, то даст -1
    if (last_word == '\n') {
      if (entity.flagS && word == '\n') {  // s - сжимает неск пустых строк
        if (empty_del) {
          empty = true;
        }
        empty_del = true;
      } else {
        empty_del = false;
      }
      if (entity.flagB) {  //нумерует не пустые строки
        if (word != '\n') {
          printf("%6d\t", ++lineCount);
        } else if (entity.flagE && !empty) {
          printf("      \t");
        }
      } else if (entity.flagN) {
        if (!empty) {
          printf("%6d\t", ++lineCount);
        }
      }
    }
    if (!empty) {
      if (!*table[word]) {
        printf("%c", '\0');  //то печатаем 0 символов и заканчиваем
      } else {
        printf("%s", table[word]);
      }
    }
    empty = false;
    last_word = word;
  }
}
