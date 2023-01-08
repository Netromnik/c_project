typedef struct {
  int len;
  int max_len;
  char* start;
} stack_char;

stack_char init();
stack_char append(stack_char stack, char c, int* err);
stack_char stdin_input(int* err);
