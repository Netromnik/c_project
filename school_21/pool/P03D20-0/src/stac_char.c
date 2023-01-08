#include <stdlib.h>

#include "stack_char.h"

stack_char init_stack_char(int* err) {
  stack_char init_st;
  init_st.len = 0;
  init_st.max_len = 100;
  init_st.start = malloc(sizeof(char) * 100);
  if (!init_st.start) *err = 1;
  return init_st;
}

void delete_c(stack_char stack) {
  if (stack.start) free(stack.start);
}

stack_char append_c(stack_char stack, char data, int* err) {
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

stack_char pop_c(stack_char stack, char* data) {
  if (stack.len == 0) {
    *data = -1;
  } else {
    *data = stack.start[stack.len];
    stack.len--;
  }
  return stack;
}
