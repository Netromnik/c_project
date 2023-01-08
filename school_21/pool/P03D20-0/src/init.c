#include "header.h"

priory* init_priory() {
  static priory priority[] = {{.c = '+', .p = 1},
                              {.c = '-', .p = 1},
                              {.c = '*', .p = 2},
                              {.c = '/', .p = 2},
                              {.c = '?', .p = MAX_PRIORITY},
                              {.c = '(', .p = -1},
                              {.c = 'q', .p = MAX_PRIORITY},
                              {.c = 'c', .p = MAX_PRIORITY},
                              {.c = 's', .p = MAX_PRIORITY},
                              {.c = 'g', .p = MAX_PRIORITY},
                              {.c = 'a', .p = MAX_PRIORITY},
                              {.c = 'l', .p = MAX_PRIORITY},
                              {.c = '^', .p = MAX_PRIORITY}

  };
  return priority;
}
