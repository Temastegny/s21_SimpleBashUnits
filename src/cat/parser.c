#include "./head.h"

void parser(int argc, char* argv[], flags_t* flags) {
  char* short_option = "+benstv";

  struct option long_option[] = {{"optb", no_argument, NULL, 1},
                                 {"opte", no_argument, NULL, 1},
                                 {"optn", no_argument, NULL, 1},
                                 {"opts", no_argument, NULL, 1},
                                 {"optt", no_argument, NULL, 1},
                                 {"optv", no_argument, NULL, 1},
                                 {NULL, 0, NULL, 0}};

  int rez = 0;
  int option_index = 0;

  while ((rez = getopt_long(argc, argv, short_option, long_option,
                            &option_index)) != -1) {
    switch (rez) {
      case 'b': {
        flags->b = 1;
        flags->n = 0;
        break;
      }
      case 'e': {
        flags->e = 1;
        flags->v = 1;
        break;
      }
      case 'n': {
        if (flags->b == 1) {
          flags->n = 0;
        } else {
          flags->n = 1;
        }
        break;
      }
      case 's': {
        flags->s = 1;
        break;
      }
      case 't': {
        flags->t = 1;
        flags->v = 1;
        break;
      }
      case 'v': {
        flags->v = 1;
        break;
      }
    }
  }
}