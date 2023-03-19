#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isAssignment(char* str, bool* error_flag);

bool isVariable(char* str);

bool areBracketsBalanced(char* str);

bool isEqual(char* str1, char* str2);

#endif
