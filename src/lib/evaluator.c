#include "evaluator.h"
#include "tokenizer.h"
#include "math.h"
#include <ctype.h>

bool isBracketBalanced(char* expression) {
    int count = 0;
    for (int i = 0; expression[i]; i++) {
        if (expression[i] == '(') {
            count++;
        } else if (expression[i] == ')') {
            count--;
        }
    }
    return count == 0;
}

bool isOperatorOrderCorrect(char* expression) {
    // TODO: Implement this function
    return 1;
}

bool doesExpressionStartWithOperator(char* expression) {
    for (int i = 0; expression[i]; i++) {
        if (expression[i] == ' ') {
            continue;
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '&' || expression[i] == '|') {
            return 1;
        } else {
            return 0;
        }
    }
    return 0;
}

bool isValid(char* expression) {
    bool validity = true;
    validity &= isBracketBalanced(expression);
    validity &= isOperatorOrderCorrect(expression);
    validity &= !doesExpressionStartWithOperator(expression);
    return validity;
}

int evaluate(char* expression, hashmap* variables, bool* error_flag) {
    if (isValid(expression)) {
        char* sign_operators = "";
        int* values = malloc(sizeof(int) * 256);
        int values_count = 0;
        for (int i = 0; expression[i]; i++) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*'|| expression[i] == '&' || expression[i] == '|') {
                sign_operators = strcat(sign_operators, expression[i]);
            }
            if (expression[i] == '(') {
                if (i - 3 >= 0 && expression[i - 3] == 'x' && expression[i - 2] == 'o' && expression[i - 1] == 'r') {
                    int j = i + 1;
                    char* first_operand = malloc(sizeof(char) * 256);
                    for (; expression[j]; j++) {
                        if (expression[j] == ',') {
                            break;
                        } else {
                            first_operand[j - i - 1] = expression[j];
                        }
                    }
                    first_operand[j - i - 1] = 0;
                    int k = j + 1;
                    char* second_operand = malloc(sizeof(char) * 256);
                    for (; expression[k]; k++) {
                        if (expression[k] == ')') {
                            break;
                        } else {
                            second_operand[k - j - 1] = expression[k];
                        }
                    }
                    second_operand[k - j - 1] = 0;
                    int first_operand_value = evaluate(first_operand, variables, error_flag);
                    int second_operand_value = evaluate(second_operand, variables, error_flag);
                    if (*error_flag == 1) {
                        return 0;
                    }
                    i = k - 1;
                    values[values_count++] = xor(first_operand_value, second_operand_value);
                }
                else if (i - 2 >= 0 && expression[i - 2] == 'l' && expression[i - 1] == 's') {
                    int j = i + 1;
                    char* first_operand = malloc(sizeof(char) * 256);
                    for (; expression[j]; j++) {
                        if (expression[j] == ',') {
                            break;
                        } else {
                            first_operand[j - i - 1] = expression[j];
                        }
                    }
                    first_operand[j - i - 1] = 0;
                    int k = j + 1;
                    char* second_operand = malloc(sizeof(char) * 256);
                    for (; expression[k]; k++) {
                        if (expression[k] == ')') {
                            break;
                        } else {
                            second_operand[k - j - 1] = expression[k];
                        }
                    }
                    second_operand[k - j - 1] = 0;
                    int first_operand_value = evaluate(first_operand, variables, error_flag);
                    int second_operand_value = evaluate(second_operand, variables, error_flag);
                    if (*error_flag == 1) {
                        return 0;
                    }
                    i = k - 1;
                    values[values_count++] = ls(first_operand_value, second_operand_value);
                }
                else if (i - 2 >= 0 && expression[i - 2] == 'r' && expression[i - 1] == 's') {
                    int j = i + 1;
                    char* first_operand = malloc(sizeof(char) * 256);
                    for (; expression[j]; j++) {
                        if (expression[j] == ',') {
                            break;
                        } else {
                            first_operand[j - i - 1] = expression[j];
                        }
                    }
                    first_operand[j - i - 1] = 0;
                    int k = j + 1;
                    char* second_operand = malloc(sizeof(char) * 256);
                    for (; expression[k]; k++) {
                        if (expression[k] == ')') {
                            break;
                        } else {
                            second_operand[k - j - 1] = expression[k];
                        }
                    }
                    second_operand[k - j - 1] = 0;
                    int first_operand_value = evaluate(first_operand, variables, error_flag);
                    int second_operand_value = evaluate(second_operand, variables, error_flag);
                    if (*error_flag == 1) {
                        return 0;
                    }
                    i = k - 1;
                    values[values_count++] = rs(first_operand_value, second_operand_value);
                }
                else if (i - 2 >= 0 && expression[i - 2] == 'l' && expression[i - 1] == 'r') {
                    int j = i + 1;
                    char* first_operand = malloc(sizeof(char) * 256);
                    for (; expression[j]; j++) {
                        if (expression[j] == ',') {
                            break;
                        } else {
                            first_operand[j - i - 1] = expression[j];
                        }
                    }
                    first_operand[j - i - 1] = 0;
                    int k = j + 1;
                    char* second_operand = malloc(sizeof(char) * 256);
                    for (; expression[k]; k++) {
                        if (expression[k] == ')') {
                            break;
                        } else {
                            second_operand[k - j - 1] = expression[k];
                        }
                    }
                    second_operand[k - j - 1] = 0;
                    int first_operand_value = evaluate(first_operand, variables, error_flag);
                    int second_operand_value = evaluate(second_operand, variables, error_flag);
                    if (*error_flag == 1) {
                        return 0;
                    }
                    i = k - 1;
                    values[values_count++] = lr(first_operand_value, second_operand_value);
                }
                else if (i - 2 >= 0 && expression[i - 2] == 'r' && expression[i - 1] == 'r') {
                    int j = i + 1;
                    char* first_operand = malloc(sizeof(char) * 256);
                    for (; expression[j]; j++) {
                        if (expression[j] == ',') {
                            break;
                        } else {
                            first_operand[j - i - 1] = expression[j];
                        }
                    }
                    first_operand[j - i - 1] = 0;
                    int k = j + 1;
                    char* second_operand = malloc(sizeof(char) * 256);
                    for (; expression[k]; k++) {
                        if (expression[k] == ')') {
                            break;
                        } else {
                            second_operand[k - j - 1] = expression[k];
                        }
                    }
                    second_operand[k - j - 1] = 0;
                    int first_operand_value = evaluate(first_operand, variables, error_flag);
                    int second_operand_value = evaluate(second_operand, variables, error_flag);
                    if (*error_flag == 1) {
                        return 0;
                    }
                    i = k - 1;
                    values[values_count++] = rr(first_operand_value, second_operand_value);
                }
                else if (i - 3 >= 0 && expression[i - 3] == 'n' && expression[i - 2] == 'o' && expression[i - 1] == 't') {
                    int j = i + 1;
                    char* first_operand = malloc(sizeof(char) * 256);
                    for (; expression[j]; j++) {
                        if (expression[j] == ')') {
                            break;
                        } else {
                            first_operand[j - i - 1] = expression[j];
                        }
                    }
                    first_operand[j - i - 1] = 0;
                    int first_operand_value = evaluate(first_operand, variables, error_flag);
                    if (*error_flag == 1) {
                        return 0;
                    }
                    i = j - 1;
                    values[values_count++] = not(first_operand_value);
                }
                else {
                    int j = i + 1;
                    char* first_operand = malloc(sizeof(char) * 256);
                    for (; expression[j]; j++) {
                        if (expression[j] == ')') {
                            break;
                        } else {
                            first_operand[j - i - 1] = expression[j];
                        }
                    }
                    first_operand[j - i - 1] = 0;
                    if (*error_flag == 1) {
                        return 0;
                    }
                    i = j - 1;
                    values[values_count++] = evaluate(first_operand, variables, error_flag);
                }
            }
            if (isalpha(expression[i])) {
                if (expression[i + 1] && isalpha(expression[i + 1])) continue;
                char* variable_name = malloc(sizeof(char) * 256);
                int j = i;
                for (; j >= 0; j--) {
                    if (!isalpha(expression[j])) {
                        break;
                    }
                }
                int k = 0;
                for (j = j + 1; j <= i; j++) {
                    variable_name[k++] = expression[j];
                }
                variable_name[k] = 0;
                if (strcmp(variable_name, "xor") == 0) continue;
                if (strcmp(variable_name, "not") == 0) continue;
                if (strcmp(variable_name, "and") == 0) continue;
                if (strcmp(variable_name, "or") == 0) continue;
                if (strcmp(variable_name, "ls") == 0) continue;
                if (strcmp(variable_name, "rs") == 0) continue;
                if (strcmp(variable_name, "lr") == 0) continue;
                if (strcmp(variable_name, "rr") == 0) continue;

                values[values_count++] = map_get(variables, variable_name);
            }
            if (isdigit(expression[i])) {
                if (expression[i + 1] && isdigit(expression[i + 1])) continue;
                int j = i;
                for (; j >= 0; j--) {
                    if (!isdigit(expression[j])) {
                        break;
                    }
                }
                int k = 0;
                char* number = malloc(sizeof(char) * 256);
                for (j = j + 1; j <= i; j++) {
                    number[k++] = expression[j];
                }
                number[k] = 0;
                values[values_count++] = atoi(number);
            }
        }
        if (*error_flag == 1) {
            return 0;
        }
    } else {
        *error_flag = 1;
        return 0;
    }
}