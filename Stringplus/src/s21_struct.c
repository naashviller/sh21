#include "s21_struct.h"

#include <stdarg.h>
#include <stdlib.h>

void initList(struct List* ptrList) {
  if (ptrList != NULL) {
    int* flags = (int*)calloc(5, sizeof(int));
    char* length = (char*)calloc(2, sizeof(char));
    char* sscanf_str = (char*)calloc(2, sizeof(char));
    if (flags != NULL && length != NULL && sscanf_str != NULL) {
      ptrList->flags = flags;
      ptrList->length = length;
      ptrList->sscanf_str = sscanf_str;
    } else {
      if (flags != NULL) {
        free(flags);
        flags = NULL;
      }
      if (length != NULL) {
        free(length);
        length = NULL;
      }
      if (sscanf_str != NULL) {
        free(sscanf_str);
        sscanf_str = NULL;
      }

      free(ptrList);
      ptrList = NULL;
    }
  }
}

void destroyList(struct List* list) {
  if (list != NULL) {
    if (list->flags != NULL) {
      free(list->flags);
      list->flags = NULL;
    }
    if (list->length != NULL) {
      free(list->length);
      list->length = NULL;
    }
    if (list->sscanf_str != NULL) {
      free(list->sscanf_str);
      list->sscanf_str = NULL;
    }
    free(list);
  }
}
