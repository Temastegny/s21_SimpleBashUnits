#ifndef HEAD_H
#define HEAD_H

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "string.h"

typedef struct flags_s {
  char* search;
  int e;
  char* template;
  int i;
  int v;
  int c;
  int l;
  int n;
} flags_t;

void parser(int argc, char* argv[], flags_t* flags);
void reader(int argc, char* argv[], flags_t* flags);

#endif