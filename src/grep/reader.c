#include "./head.h"

void reader(int argc, char *argv[], flags_t *flags) {
  char *filenames[100] = {NULL};
  char *line = NULL;
  size_t len;
  size_t read;
  regex_t regex;
  int match;
  int counter_c = 0;
  int counter_files = 0;
  int counter_str = 0;
  int x = 1;

  if (!(flags->e && flags->template)) {
    flags->search = argv[optind++];
  }
  counter_files = argc - optind;

  for (int i = 0; optind < argc; i++) {
    filenames[i] = argv[optind];

    FILE *f = fopen(filenames[i], "r");
    if ((f = fopen(filenames[i], "r")) == NULL) {
      fprintf(stderr, "Cannot open file.\n");
    }

    if (f) {
      if (flags->e && flags->template) {
        regcomp(&regex, flags->template, 0);
      } else if (flags->i) {
        regcomp(&regex, flags->search, REG_ICASE);
      } else {
        regcomp(&regex, flags->search, 0);
      }
      while ((read = getline(&line, &len, f)) != (size_t)-1) {
        counter_str++;
        match = regexec(&regex, line, 0, NULL, 0);
        if (!match) {
          counter_c++;
        }
        if (!match && flags->v == 0 && flags->c == 0 && flags->l == 0 &&
            flags->n == 0) {
          if (counter_files == 1) {
            printf("%s", line);
          }
          if (counter_files > 1) {
            printf("%s:%s", filenames[i], line);
          }
        }
        if (flags->v && match == REG_NOMATCH && flags->c == 0 &&
            flags->l == 0 && flags->n == 0) {
          if (counter_files == 1) {
            printf("%s", line);
          }
          if (counter_files > 1) {
            printf("%s:%s", filenames[i], line);
          }
        }
        if (flags->n && !match) {
          if (counter_files == 1) {
            printf("%d:%s", counter_str, line);
          }
          if (counter_files > 1) {
            printf("%s:%d:%s", filenames[i], counter_str, line);
          }
        }
        if (line) {
          free(line);
          line = NULL;
        }
      }
      if (flags->c) {
        if (counter_files == 1) {
          printf("%d\n", counter_c);
        } else if (counter_files > 1) {
          printf("%s:%d\n", filenames[i], counter_c);
        }
      }
      if (flags->l) {
        if (counter_c) {
          printf("%s\n", filenames[i]);
        }
      }
      if (flags->v && (x < counter_files || counter_files == 1)) {
        printf("\n");
        x++;
      }
      counter_c = 0;
      regfree(&regex);
      fclose(f);
    }
    optind++;
    counter_str = 0;
  }
  free(line);
}