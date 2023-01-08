#ifndef SRC_CHAR_D
#define SRC_CHAR_D
#include "header.h"

typedef struct {
  int len;
  int max_len;
  double* start;
} stack_double;

stack_double init_stack_double(int* err);
void delete_d(stack_double stack);
stack_double append_d(stack_double stack, double data, int* err);
stack_double pop_d(stack_double stack, double* data);

#endif  // SRC_CHAR_D
