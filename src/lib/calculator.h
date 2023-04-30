#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#include "hashmap.h"
#include "validator.h"
#include "evaluator.h"
#include "printer.h"


/*
* This function is the main function of the calculator.
* It takes a string as input and evaluates it.
* It also handles the assignment of variables.
* @param input: The string to be evaluated.
*/
void calculator(char* line, int line_number);

/*
* This function is used to find the assignment sign in the input string.
* @param input: The string to be evaluated.
* @return: The index of the assignment sign.
*/
int find_assignment_sign(char* input);

/*
* This function is used to check if the input string is blank.
* @param input: The string to be evaluated.
* @return: True if the string is blank, false otherwise.
*/
bool isBlank(char* input);

/*
* This function is used to copy the variable name from the input string.
* @param variable: The string to store the variable name.
* @param input: The string to be evaluated.
* @param size: The size of the variable name.
*/
void copyVariable(char* variable, char* input, int size);

#endif
