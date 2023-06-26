#include "./head.h"

void parser(int argc, char* argv[], flags_t* flags) {
  char* short_options = "e:ivcln";

  struct option long_options[] = {{"opte", required_argument, NULL, 1},
                                  {"opti", no_argument, NULL, 1},
                                  {"optv", no_argument, NULL, 1},
                                  {"optc", no_argument, NULL, 1},
                                  {"optl", no_argument, NULL, 1},
                                  {"optn", no_argument, NULL, 1},
                                  {NULL, 0, NULL, 0}};
  int rez = 0;
  int option_index = 0;

  while ((rez = getopt_long(argc, argv, short_options, long_options,
                            &option_index)) != -1) {
    switch (rez) {
      case 'e': {
        flags->e = 1;
        flags->template = optarg;
        break;
      }
      case 'i': {
        flags->i = 1;
        break;
      }
      case 'v': {
        flags->v = 1;
        break;
      }
      case 'c': {
        flags->c = 1;
        break;
      }
      case 'l': {
        flags->l = 1;
        break;
      }
      case 'n': {
        flags->n = 1;
        break;
      }
    }
  }
}