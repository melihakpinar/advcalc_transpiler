#include "hashmap.h"
#include <stdbool.h>

#ifndef EVALUATOR_H
#define EVALUATOR_H

/*
* @param: expression: char*
* @return: int
*/
int isValid(char* expression);

/*
* @param: str: char*
* @return: int
*/
int evaluate(char* expression, hashmap* variables, bool *error_flag);

#endif
