#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <stdbool.h>
#include <ctype.h>
#include <string.h>


/*
* This function is used to check if the expression is an assignment.
* @param: str: char*
* @return: true if the expression is an assignment, false otherwise.
*/
bool isAssignment(char* str, bool* error_flag);

/*
* This function is used to check if the string is a valid variable name.
* @param: str: char*
* @return: true if the string is a valid variable name, false otherwise.
*/
bool isVariable(char* str);

/*
* This function is used to check if the string is a keyword.
* @param: str: char*
* @return: true if the string is a keyword, false otherwise.
*/
bool isKeyword(char* str);

/*
* This function is used to check if brackets are balanced.
* @param: str: char*
* @return: bool
*/
bool areBracketsBalanced(char* str);

/*
* This function is used to compare two strings.
* @param: str1: char*
* @param: str2: char*
* @return: true if the strings are equal, false otherwise.
*/
bool isEqual(char* str1, char* str2);

/*
* This function is used to check if there are two operators in a row.
* @param: expression: char*
* @return: true if the expression is correct, false otherwise.
*/
bool isOperatorOrderCorrect(char* expression);

/*
* This function is used to check if the expression starts or ends with an operator.
* @param: expression: char*
* @return: true if the expression starts or ends with an operator, false otherwise
*/
bool doesExpressionStartOrEndWithOperator(char* expression);

/*
* This function is used to check if the expression is valid.
* @param: expression: char*
* @return: true if the expression is valid, false otherwise.
*/
bool isValid(char* expression);

#endif
