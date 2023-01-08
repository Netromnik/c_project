#ifndef CHAR_D
#define CHAR_D
#include "header.h"

typedef struct {
  int len;
  int max_len;
  char* start;
} stack_char;

stack_char init_stack_char(int* err);
void delete_c(stack_char stack);
stack_char append_c(stack_char stack, char data, int* err);
stack_char pop_c(stack_char stack, char* data);
stack_char to_pn(string s_str, int* err);

#endif