#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "hashmap.h"
#include "math.h"
#include "validator.h"


/*
* This function is used to evaluate the expression.
* @param: expression: The expression to be evaluated.
* @param: variables: The hashmap to store the variables.
* @param: error_flag: The flag to check if there is an error.
* @return: The result of the expression.
*/
char* evaluate(char* expression, hashmap* variables, bool* error_flag, int* address);

#endif
