#include "./head.h"

void reader(int argc, char* argv[], flags_t* flags) {
  while (optind < argc) {
    FILE* f = fopen(argv[optind], "r");
    if ((f = fopen(argv[optind], "r")) == NULL) {
      fprintf(stderr, "Cannot open flie.\n");
    }
    if (f) {
      int cur = 0;  // current symbol
      int str_counter = 1;
      int pr = 0;
      int i = 0;
      int j = 0;

      while (1) {
        pr = cur;
        cur = fgetc(f);

        if (cur == EOF) break;

        if (flags->s == 1) {
          if (cur == '\n') {
            i++;
          } else {
            i = 0;
          }
        }
        if ((flags->b == 1) && (i < 3) &&
            ((pr == '\n' && cur != '\n') || (!pr && cur != '\n'))) {
          printf("%6.d\t", str_counter);
          str_counter++;
        } else if ((flags->n == 1) && (i < 3) &&
                   ((!pr && cur == '\n') || (pr == '\n') || (!pr))) {
          printf("%6.d\t", str_counter);
          str_counter++;
        }
        if ((flags->t == 1) && (cur == '\t')) {
          printf("^I");
          j = 1;
        }
        if (flags->v == 1 && cur == 127) {
          printf("^?");
          j = 1;
        }
        if (flags->v == 1 && cur <= 31 && cur != '\n' && cur != '\t') {
          printf("^%c", (cur + 64));
          j = 1;
        }
        if ((flags->e == 1) && (cur == '\n') && (i < 3)) {
          printf("$");
        }
        if (i < 3 && j != 1) {
          printf("%c", cur);
        }

        j = 0;
      }
    }
    fclose(f);
    optind++;
  }
}