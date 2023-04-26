#include "evaluator.h"

int64_t evaluate(char* expression, hashmap* variables, bool* error_flag) {
    if (!isValid(expression)) {
        *error_flag = 1;
        return 0;
    }
    char sign_operators[256] = "";
    int64_t values[256];
    int values_count = 0;
    for (int i = 0; expression[i]; i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '&' || expression[i] == '|') {
            sign_operators[strlen(sign_operators)] = expression[i];
        }
        else if (expression[i] == '(') {
            int keyword_index = i - 1; // variable to find the keyword
            int type = -1; // 0: xor, 1: ls, 2: rs, 3: lr, 4: rr, 5: not
            for (; keyword_index >= 2; keyword_index--) {
                if (expression[keyword_index] == ' ') {
                    continue;
                } else if (expression[keyword_index] == 'r' && expression[keyword_index - 1] == 'o' && expression[keyword_index - 2] == 'x') {
                    type = 0;
                    break;
                } else if (expression[keyword_index] == 't' && expression[keyword_index - 1] == 'o' && expression[keyword_index - 2] == 'n') {
                    type = 5;
                    break;
                } else {
                    break;
                }
            }
            for (; keyword_index >= 1; keyword_index--) {
                if (expression[keyword_index] == ' ') {
                    continue;
                } else if (expression[keyword_index] == 's' && expression[keyword_index - 1] == 'l') {
                    type = 1;
                    break;
                } else if (expression[keyword_index] == 's' && expression[keyword_index - 1] == 'r') {
                    type = 2;
                    break;
                } else if (expression[keyword_index] == 'r' && expression[keyword_index - 1] == 'l') {
                    type = 3;
                    break;
                } else if (expression[keyword_index] == 'r' && expression[keyword_index - 1] == 'r') {
                    type = 4;
                    break;
                } else {
                    break;
                }
            }
            if (type == 0) {
                int j = i + 1;
                char first_operand[256];
                int brackets = 0;
                for (; expression[j]; j++) {
                    if (expression[j] == '(') brackets++;
                    if (expression[j] == ')') brackets--;
                    if (expression[j] == ',' && brackets == 0) {
                        break;
                    } else {
                        first_operand[j - i - 1] = expression[j];
                    }
                }
                first_operand[j - i - 1] = 0;
                int k = j + 1;
                char second_operand[256];
                brackets = 0;
                for (; expression[k]; k++) {
                    if (expression[k] == ')' && brackets == 0) {
                        break;
                    } else {
                        second_operand[k - j - 1] = expression[k];
                    }
                    if (expression[k] == '(') brackets++;
                    if (expression[k] == ')') brackets--;
                }
                second_operand[k - j - 1] = 0;
                int64_t first_operand_value = evaluate(first_operand, variables, error_flag);
                int64_t second_operand_value = evaluate(second_operand, variables, error_flag);
                if (*error_flag == 1) {
                    return 0;
                }
                i = k;
                values[values_count++] = bxor(first_operand_value, second_operand_value);
            }
            else if (type == 1) {
                int j = i + 1;
                char first_operand[256];
                int brackets = 0;
                for (; expression[j]; j++) {
                    if (expression[j] == '(') brackets++;
                    if (expression[j] == ')') brackets--;
                    if (expression[j] == ',' && brackets == 0) {
                        break;
                    } else {
                        first_operand[j - i - 1] = expression[j];
                    }
                }
                first_operand[j - i - 1] = 0;
                int k = j + 1;
                char second_operand[256];
                brackets = 0;
                for (; expression[k]; k++) {
                    if (expression[k] == ')' && brackets == 0) {
                        break;
                    } else {
                        second_operand[k - j - 1] = expression[k];
                    }
                    if (expression[k] == '(') brackets++;
                    if (expression[k] == ')') brackets--;
                }
                second_operand[k - j - 1] = 0;
                int64_t first_operand_value = evaluate(first_operand, variables, error_flag);
                int64_t second_operand_value = evaluate(second_operand, variables, error_flag);
                if (*error_flag == 1) {
                    return 0;
                }
                i = k;
                values[values_count++] = ls(first_operand_value, second_operand_value);
            }
            else if (type == 2) {
                int j = i + 1;
                char first_operand[256];
                int brackets = 0;
                for (; expression[j]; j++) {
                    if (expression[j] == '(') brackets++;
                    if (expression[j] == ')') brackets--;
                    if (expression[j] == ',' && brackets == 0) {
                        break;
                    } else {
                        first_operand[j - i - 1] = expression[j];
                    }
                }
                first_operand[j - i - 1] = 0;
                int k = j + 1;
                char second_operand[256];
                brackets = 0;
                for (; expression[k]; k++) {
                    if (expression[k] == ')' && brackets == 0) {
                        break;
                    } else {
                        second_operand[k - j - 1] = expression[k];
                    }
                    if (expression[k] == '(') brackets++;
                    if (expression[k] == ')') brackets--;
                }
                second_operand[k - j - 1] = 0;
                int64_t first_operand_value = evaluate(first_operand, variables, error_flag);
                int64_t second_operand_value = evaluate(second_operand, variables, error_flag);
                if (*error_flag == 1) {
                    return 0;
                }
                i = k;
                values[values_count++] = rs(first_operand_value, second_operand_value);
            }
            else if (type == 3) {
                int j = i + 1;
                char first_operand[256];
                int brackets = 0;
                for (; expression[j]; j++) {
                    if (expression[j] == '(') brackets++;
                    if (expression[j] == ')') brackets--;
                    if (expression[j] == ',' && brackets == 0) {
                        break;
                    } else {
                        first_operand[j - i - 1] = expression[j];
                    }
                }
                first_operand[j - i - 1] = 0;
                int k = j + 1;
                char second_operand[256];
                brackets = 0;
                for (; expression[k]; k++) {
                    if (expression[k] == ')' && brackets == 0) {
                        break;
                    } else {
                        second_operand[k - j - 1] = expression[k];
                    }
                    if (expression[k] == '(') brackets++;
                    if (expression[k] == ')') brackets--;
                }
                second_operand[k - j - 1] = 0;
                int64_t first_operand_value = evaluate(first_operand, variables, error_flag);
                int64_t second_operand_value = evaluate(second_operand, variables, error_flag);
                if (*error_flag == 1) {
                    return 0;
                }
                i = k;
                values[values_count++] = lr(first_operand_value, second_operand_value);
            }
            else if (type == 4) {
                int j = i + 1;
                char first_operand[256];
                int brackets = 0;
                for (; expression[j]; j++) {
                    if (expression[j] == '(') brackets++;
                    if (expression[j] == ')') brackets--;
                    if (expression[j] == ',' && brackets == 0) {
                        break;
                    } else {
                        first_operand[j - i - 1] = expression[j];
                    }
                }
                first_operand[j - i - 1] = 0;
                int k = j + 1;
                char second_operand[256];
                brackets = 0;
                for (; expression[k]; k++) {
                    if (expression[k] == ')' && brackets == 0) {
                        break;
                    } else {
                        second_operand[k - j - 1] = expression[k];
                    }
                    if (expression[k] == '(') brackets++;
                    if (expression[k] == ')') brackets--;
                }
                second_operand[k - j - 1] = 0;
                int64_t first_operand_value = evaluate(first_operand, variables, error_flag);
                int64_t second_operand_value = evaluate(second_operand, variables, error_flag);
                if (*error_flag == 1) {
                    return 0;
                }
                i = k;
                values[values_count++] = rr(first_operand_value, second_operand_value);
            }
            else if (type == 5) {
                int j = i + 1;
                char first_operand[256];
                int brackets = 0;
                for (; expression[j]; j++) {
                    if (expression[j] == ')' && brackets == 0) {
                        break;
                    } else {
                        first_operand[j - i - 1] = expression[j];
                    }
                    if (expression[j] == '(') brackets++;
                    if (expression[j] == ')') brackets--;
                }
                first_operand[j - i - 1] = 0;
                int64_t first_operand_value = evaluate(first_operand, variables, error_flag);
                if (*error_flag == 1) {
                    return 0;
                }
                i = j;
                values[values_count++] = bnot(first_operand_value);
            }
            else { // No keywords, normal brackets
                int j = i + 1;
                char first_operand[256];
                int brackets = 0;
                for (; expression[j]; j++) {
                    if (expression[j] == ')' && brackets == 0) {
                        break;
                    } else {
                        first_operand[j - i - 1] = expression[j];
                    }
                    if (expression[j] == '(') brackets++;
                    if (expression[j] == ')') brackets--;
                }
                first_operand[j - i - 1] = 0;
                values[values_count++] = evaluate(first_operand, variables, error_flag);
                if (*error_flag == 1) {
                    return 0;
                }
                i = j;
            }
        }
        else if (isalpha(expression[i])) {
            if (expression[i + 1] && isalpha(expression[i + 1])) continue;
            char variable_name[256];
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
            if (!isVariable(variable_name)) {
                // Check if the variable name is valid
                *error_flag = 1;
                return 0;
            }
            if (isKeyword(variable_name)) {
                // Do nothing and i will see opening bracket
                continue;
            }
            values[values_count++] = map_get(variables, variable_name);
        }
        else if (isdigit(expression[i])) {
            if (expression[i + 1] && isdigit(expression[i + 1])) continue;
            int j = i;
            for (; j >= 0; j--) {
                if (!isdigit(expression[j])) {
                    break;
                }
            }
            int k = 0;
            char number[256];
            for (j = j + 1; j <= i; j++) {
                number[k++] = expression[j];
            }
            number[k] = 0;
            values[values_count++] = atoll(number);
        }
        else if(expression[i] != ' '){
            *error_flag = true;
            return 0;
        }
    }
    if (values_count - 1 != (int)strlen(sign_operators)) {
        *error_flag = 1;
        return 0;
    }
    // Do all * operations
    for (int i = 0; i < (int)strlen(sign_operators); i++) {
        if (sign_operators[i] == '*') {
            values[i] = multiple(values[i], values[i + 1]);
            for (int j = i + 1; j < values_count - 1; j++) {
                values[j] = values[j + 1];
            }
            values_count--;
            for (int j = i; j < (int)strlen(sign_operators) - 1; j++) {
                sign_operators[j] = sign_operators[j + 1];
            }
            sign_operators[strlen(sign_operators) - 1] = 0;
            i--;
        }
        if (sign_operators[i] == '/') {
            if (values[i + 1] == 0) {
                *error_flag = 1;
                return 0;
            }
            values[i] = divide(values[i], values[i + 1]);
            for (int j = i + 1; j < values_count - 1; j++) {
                values[j] = values[j + 1];
            }
            values_count--;
            for (int j = i; j < (int)strlen(sign_operators) - 1; j++) {
                sign_operators[j] = sign_operators[j + 1];
            }
            sign_operators[strlen(sign_operators) - 1] = 0;
            i--;
        }
    }
    // Do all + and - operations
    for (int i = 0; i < (int)strlen(sign_operators); i++) {
        if (sign_operators[i] == '+') {
            values[i] = sum(values[i], values[i + 1]);
            for (int j = i + 1; j < values_count - 1; j++) {
                values[j] = values[j + 1];
            }
            values_count--;
            for (int j = i; j < (int)strlen(sign_operators) - 1; j++) {
                sign_operators[j] = sign_operators[j + 1];
            }
            sign_operators[strlen(sign_operators) - 1] = 0;
            i--;
        }
        else if (sign_operators[i] == '-') {
            values[i] = substract(values[i], values[i + 1]);
            for (int j = i + 1; j < values_count - 1; j++) {
                values[j] = values[j + 1];
            }
            values_count--;
            for (int j = i; j < (int)strlen(sign_operators) - 1; j++) {
                sign_operators[j] = sign_operators[j + 1];
            }
            sign_operators[strlen(sign_operators) - 1] = 0;
            i--;
        }
    }
    // Do all & operations
    for (int i = 0; i < (int)strlen(sign_operators); i++) {
        if (sign_operators[i] == '&') {
            values[i] = band(values[i], values[i + 1]);
            for (int j = i + 1; j < values_count - 1; j++) {
                values[j] = values[j + 1];
            }
            values_count--;
            for (int j = i; j < (int)strlen(sign_operators) - 1; j++) {
                sign_operators[j] = sign_operators[j + 1];
            }
            sign_operators[strlen(sign_operators) - 1] = 0;
            i--;
        }
    }
    // Do all | operations
    for (int i = 0; i < (int)strlen(sign_operators); i++) {
        if (sign_operators[i] == '|') {
            values[i] = bor(values[i], values[i + 1]);
            for (int j = i + 1; j < values_count - 1; j++) {
                values[j] = values[j + 1];
            }
            values_count--;
            for (int j = i; j < (int)strlen(sign_operators) - 1; j++) {
                sign_operators[j] = sign_operators[j + 1];
            }
            sign_operators[strlen(sign_operators) - 1] = 0;
            i--;
        }
    }
    return values[0];
}
