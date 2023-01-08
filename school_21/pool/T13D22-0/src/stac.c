#include "stac.h"

#include <stdio.h>
#include <stdlib.h>

stack_char init() {
  stack_char init = {
      .len = 0, .max_len = 10, .start = malloc(sizeof(char) * 10)};
  for (int i = 0; i < 10; i++) init.start[i] = 0;
  return init;
}
stack_char append(stack_char stack, char c, int* err) {
  if (stack.len == stack.max_len) {
    stack.max_len += 10;
    stack.start = realloc(stack.start, sizeof(char) * stack.max_len + 10);
    if (!stack.start) *err = 0;
  }
  stack.start[stack.len] = c;
  stack.len++;
  return stack;
}

stack_char stdin_input(int* err) {
  stack_char stack = init();
  while (!*err && stack.start[stack.len - 1] != '\n') {
    stack = append(stack, getchar(), err);
  }
  stack.start[stack.len - 1] = 0;
  return stack;
}
