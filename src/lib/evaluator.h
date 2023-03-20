#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <stdbool.h>

#include "hashmap.h"
#include "math.h"
#include "validator.h"

/*
* @param: str: char*
* @return: int
*/
int evaluate(char* expression, hashmap* variables, bool* error_flag);

#endif
