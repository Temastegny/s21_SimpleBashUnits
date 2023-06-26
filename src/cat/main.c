#include "./head.h"

flags_t *init() {
  flags_t *flags;
  flags = malloc(sizeof(flags_t));
  flags->b = 0;
  flags->e = 0;
  flags->n = 0;
  flags->s = 0;
  flags->t = 0;
  flags->v = 0;

  return flags;
}

int main(int argc, char *argv[]) {
  flags_t *flags;

  flags = init();

  parser(argc, argv, flags);

  reader(argc, argv, flags);

  free(flags);
}