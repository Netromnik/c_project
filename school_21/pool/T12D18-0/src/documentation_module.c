#include "documentation_module.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int validate(char* data) {
  int validation_result = !strcmp(data, Available_document);
  return validation_result;
}

int* check_available_documentation_module(int (*validate)(char*),
                                          int document_count, char* p, ...) {
  va_list ap;
  va_start(ap, p);
  for (int i = 0; i < document_count; i++) {
    if (validate(p)) {
      printf("%15s : available\n", p);
    } else {
      printf("%15s : unavailable\n", p);
    }
    p = va_arg(ap, char*);
  }

  va_end(ap);
  return 0;
}
