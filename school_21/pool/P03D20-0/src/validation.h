#ifndef SRC_VALIDATION_H_
#define SRC_VALIDATION_H_

#include "header.h"

void remove_space(char*);
int check_bracket(char* string);
int check_symbol(char* string);
void replace_substring(char* string, char* substring, char* sub_str_rep);
string cast_string();
int check_validation(char* string);

typedef struct operator {
    char* name;
    char* polperf;
}operator;

#endif  // SRC_VALIDATION_H_
