#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <stdbool.h>
#include <ctype.h>

bool is_assignment(char* str);

bool is_variable(char* str);

bool is_paranthesis_valid(char* str);

bool is_equal(char* str1, char* str2);

#endif
