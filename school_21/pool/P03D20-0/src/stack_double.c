#include "stack_double.h"

#include <stdlib.h>

stack_double init_stack_double(int* err) {
  stack_double init_st;
  init_st.len = 0;
  init_st.max_len = 100;
  init_st.start = malloc(sizeof(double) * 100);
  if (!init_st.start) *err = 1;
  return init_st;
}

void delete_d(stack_double stack) {
  if (stack.start) free(stack.start);
}

stack_double append_d(stack_double stack, double data, int* err) {
  *err = 0;

  if (stack.len == stack.max_len) {
    stack.max_len += 10;
    stack.start = realloc(stack.start, sizeof(char) * stack.max_len);
    if (!stack.start) *err = 1;
  }
  stack.len++;

  if (!*err) {
    stack.start[stack.len] = data;
  }
  return stack;
}

stack_double pop_d(stack_double stack, double* data) {
  if (stack.len == 0) {
    *data = -1;
  } else {
    *data = stack.start[stack.len];
    stack.len--;
  }
  return stack;
}
