#ifndef HEAD_H
#define HEAD_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct flags_s {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
} flags_t;

void parser(int argc, char* argv[], flags_t* flags);
void reader(int argc, char* argv[], flags_t* flags);

#endif