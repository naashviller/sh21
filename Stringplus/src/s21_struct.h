#include "s21_string.h"
struct List {
  int* flags;  // Флаги - 5 флагов: -, +, ' ', #, 0
  int width;  // Ширина - число или к примеру -1(если *); (-3) когда значение не
              // было введено
  int accuracy;  // Точность - .число или к примеру -1(если *); (-3) когда
                 // значение не было введено
  char* length;  // Длина - 3 буквы: h, I, L
  char specifier;  // Спецификатор - 15 букв
  int indicator;  // 1-флаги, 2-ширина, 3-точность, 4-длина, 5-спецификатор
  int strIndex;
  char* sscanf_str;  // для sscanf
  int counter;  // для sscanf счетчик присвоенных значений
};

void initList(struct List* ptrList);
void destroyList(struct List* list);