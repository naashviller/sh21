﻿#include "cat_flags.h"

#include "s21_cat.h"

void CreateTable(const char *change_table[static 256]) {
  char *base_table[] = {
      "\00",  "\01",  "\02",  "\03",  "\04",  "\05",  "\06",  "\07",  "\b",
      "\t",   "\n",   "\v",   "\014", "\r",   "\016", "\017", "\020", "\021",
      "\022", "\023", "\024", "\025", "\026", "\027", "\030", "\031", "\032",
      "\033", "\034", "\035", "\036", "\037", " ",    "!",    "\"",   "#",
      "$",    "%",    "&",    "\'",   "(",    ")",    "*",    "+",    ",",
      "-",    ".",    "/",    "0",    "1",    "2",    "3",    "4",    "5",
      "6",    "7",    "8",    "9",    ":",    ";",    "<",    "=",    ">",
      "?",    "@",    "A",    "B",    "C",    "D",    "E",    "F",    "G",
      "H",    "I",    "J",    "K",    "L",    "M",    "N",    "O",    "P",
      "Q",    "R",    "S",    "T",    "U",    "V",    "W",    "X",    "Y",
      "Z",    "[",    "\\",   "]",    "^",    "_",    "`",    "a",    "b",
      "c",    "d",    "e",    "f",    "g",    "h",    "i",    "j",    "k",
      "l",    "m",    "n",    "o",    "p",    "q",    "r",    "s",    "t",
      "u",    "v",    "w",    "x",    "y",    "z",    "{",    "|",    "}",
      "~",    "",    "\x80", "\x81", "\x82", "\x83", "\x84", "\x85", "\x86",
      "\x87", "\x88", "\x89", "\x8a", "\x8b", "\x8c", "\x8d", "\x8e", "\x8f",
      "\x90", "\x91", "\x92", "\x93", "\x94", "\x95", "\x96", "\x97", "\x98",
      "\x99", "\x9a", "\x9b", "\x9c", "\x9d", "\x9e", "\x9f", "\xa0", "\xa1",
      "\xa2", "\xa3", "\xa4", "\xa5", "\xa6", "\xa7", "\xa8", "\xa9", "\xaa",
      "\xab", "\xac", "\xad", "\xae", "\xaf", "\xb0", "\xb1", "\xb2", "\xb3",
      "\xb4", "\xb5", "\xb6", "\xb7", "\xb8", "\xb9", "\xba", "\xbb", "\xbc",
      "\xbd", "\xbe", "\xbf", "\xc0", "\xc1", "\xc2", "\xc3", "\xc4", "\xc5",
      "\xc6", "\xc7", "\xc8", "\xc9", "\xca", "\xcb", "\xcc", "\xcd", "\xce",
      "\xcf", "\xd0", "\xd1", "\xd2", "\xd3", "\xd4", "\xd5", "\xd6", "\xd7",
      "\xd8", "\xd9", "\xda", "\xdb", "\xdc", "\xdd", "\xde", "\xdf", "\xe0",
      "\xe1", "\xe2", "\xe3", "\xe4", "\xe5", "\xe6", "\xe7", "\xe8", "\xe9",
      "\xea", "\xeb", "\xec", "\xed", "\xee", "\xef", "\xf0", "\xf1", "\xf2",
      "\xf3", "\xf4", "\xf5", "\xf6", "\xf7", "\xf8", "\xf9", "\xfa", "\xfb",
      "\xfc", "\xfd", "\xfe", "\xff"};

  memcpy(change_table, base_table, sizeof base_table);
}

void FlagV(const char *change_table[static 256]) {
  char *first_part[] = {"^@", "^A", "^B", "^C", "^D", "^E", "^F", "^G", "^H"};
  char *second_part[] = {"^K", "^L", "^M", "^N",  "^O", "^P", "^Q",
                         "^R", "^S", "^T", "^U",  "^V", "^W", "^X",
                         "^Y", "^Z", "^[", "^\\", "^]", "^^", "^_"};
  char *third_part[] = {
      "^?",   "M-^@", "M-^A",  "M-^B", "M-^C", "M-^D", "M-^E", "M-^F", "M-^G",
      "M-^H", "M-^I", "M-^J",  "M-^K", "M-^L", "M-^M", "M-^N", "M-^O", "M-^P",
      "M-^Q", "M-^R", "M-^S",  "M-^T", "M-^U", "M-^V", "M-^W", "M-^X", "M-^Y",
      "M-^Z", "M-^[", "M-^\\", "M-^]", "M-^^", "M-^_", "�",    "�",    "�",
      "�",    "�",    "�",     "�",    "�",    "�",    "�",    "�",    "�",
      "�",    "�",    "�",     "�",    "�",    "�",    "�",    "�",    "�",
      "�",    "�",    "�",     "�",    "�",    "�",    "�",    "�",    "�",
      "�",    "�",    "�",     "�",    "�",    "�",    "�",    "�",    "�",
      "�",    "�",    "�",     "�",    "�",    "�",    "�",    "�",    "�",
      "�",    "�",    "�",     "�",    "�",    "�",    "�",    "�",    "�",
      "�",    "�",    "�",     "�",    "�",    "�",    "�",    "�",    "�",
      "�",    "�",    "�",     "�",    "�",    "�",    "�",    "�",    "�",
      "�",    "�",    "�",     "�",    "�",    "�",    "�",    "�",    "�",
      "�",    "�",    "�",     "�",    "�",    "�",    "�",    "�",    "�",
      "�",    "�",    "�"};

  memcpy(change_table, first_part, sizeof first_part);
  memcpy(&change_table[11], second_part, sizeof second_part);
  memcpy(&change_table[127], third_part, sizeof third_part);
}

void FlagE(const char *change_table[static 256]) { change_table['\n'] = "$\n"; }

void FLagT(const char *change_table[static 256]) { change_table['\t'] = "^I"; }