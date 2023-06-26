#include "./head.h"

flags_t *init_flags() {
  flags_t *flags;
  flags = malloc(sizeof(flags_t));

  flags->search = NULL;
  flags->e = 0;
  flags->template = NULL;
  flags->i = 0;
  flags->v = 0;
  flags->c = 0;
  flags->l = 0;
  flags->n = 0;

  return flags;
}

int main(int argc, char *argv[]) {
  flags_t *flags;
  flags = init_flags();
  parser(argc, argv, flags);
  reader(argc, argv, flags);
  free(flags);

  return 0;
}