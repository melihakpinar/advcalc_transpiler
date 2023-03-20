#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#include "hashmap.h"
#include "validator.h"
#include "evaluator.h"

void calculator(char* input);

int find_assignment_sign(char* input);

void remove_comments(char* input);

bool isBlank(char* input);

void copyVariable(char* variable, char* input, int size);

#endif
