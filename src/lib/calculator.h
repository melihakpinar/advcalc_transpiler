#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "hashmap.h"
#include "validator.h"

void calculator(char* input);

int find_assignment_sign(char* input);

#endif