#include "hashmap.h"
#include <stdbool.h>

#ifndef EVALUATOR_H
#define EVALUATOR_H

/*
* @param: expression: char
* @return: bool
*/
bool isBracketBalanced(char* expression);

/*
* @param: expression: char
* @return: bool
*/
bool isOperatorOrderCorrect(char* expression);

/*
* @param: expression: char
* @return: bool
*/
bool doesExpressionStartOrEndWithOperator(char* expression);

/*
* @param: expression: char*
* @return: bool
*/
bool isValid(char* expression);

/*
* @param: str: char*
* @return: int
*/
int evaluate(char* expression, hashmap* variables, bool* error_flag);

#endif
