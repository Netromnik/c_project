#include <stdio.h>
#ifdef Q2
#include "documentation_module.h"
#endif

#ifdef Q
#include "print_module.h"
#endif

int main() {
#ifdef Q
  print_log(print_char, "Module_load_successb");
#endif
#ifdef Q2
  check_available_documentation_module(validate, Documents_count, Documents);
#endif

  return 0;
}
