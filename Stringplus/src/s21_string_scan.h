#include <math.h>
#include <stdarg.h>

#include "s21_string.h"
#include "s21_struct.h"

#ifndef S21_STRING_SCAN_H
#define S21_STRING_SCAN_H

#define BUFF_SIZE_SCAN 8000

int checkWidthS(char, int*);
int checkLengthS(char, char**);
int checkSpecifierS(char, char*);
int analyzeFormatS(struct List*, const char*, const char*, va_list);
int fillListS(struct List* ptrList, const char* formatSym);
int fillStr(struct List*, char**, int index, const char* exhaust, const char*);
int fillVar(struct List* ptrList, va_list, int*);

// функции обрабатывающие отдельно спецификаторы
void specifierC(struct List*, va_list);
void specifierD(struct List*, va_list);
void specifierI(struct List*, va_list);
void specifierEeFgG(struct List*, va_list);
void specifierOuXx(struct List*, va_list);
void specifierS(struct List*, va_list);
void specifierP(struct List*, va_list);
// void specifierN(struct List*, va_list, int);

// вспомогательные функции: для specifierD
s21_size_t intTranslation(struct List* ptrList);
int skipSymbols(const char* exhaust, int index);
// вспомогательные функции: для specifierI и specifierOuXx и specifierP
s21_size_t numSystemConvert(struct List* ptrList, int index);
int systemSymbolCheck(char sym);
// вспомогательные функции: для speciferEeFgG
long double convertLongNotation(struct List* ptrList);
// float convertFloatNotation(struct List* ptrList);

#endif