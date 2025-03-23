#include <errno.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#ifndef S21_CAT_H
#define S21_CAT_H

typedef struct {
  bool flagB;
  bool flagE;
  bool flagN;
  bool flagS;
  bool flagT;
  bool flagV;
} Flags;

void FileOpen(int argc, char *argv[], const char *table[static 256],
              Flags entity);
Flags CatFlags(int argc, char *argv[]);
void FileRead(Flags entity, FILE *data, const char *table[static 256]);

#endif