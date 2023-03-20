#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <stdbool.h>
#include <stdint.h>

#include "hashmap.h"
#include "math.h"
#include "validator.h"

/*
* @param: str: char*
* @return: int
*/
int64_t evaluate(char* expression, hashmap* variables, bool* error_flag);

#endif
