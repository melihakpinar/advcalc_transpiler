#include "evaluator.h"


char* value_to_string(int value, bool is_address) {
    char first_operand[256];
    if (is_address) {
        sprintf(first_operand, "%%%d", value);
    } else {
        sprintf(first_operand, "%d", value);
    }
    char* result = (char*)malloc(sizeof(char) * (strlen(first_operand) + 1));
    strcpy(result, first_operand);
    return result;
}

int string_to_value(char* string) {
    if (string[0] == '%') {
        return atoi(string + 1);
    } else {
        return atoi(string);
    }
}

char* evaluate(char* expression, hashmap* variables, bool* error_flag, int* address) {
    if (!isValid(expression)) {
        *error_flag = 1;
        return "";
    }
    char sign_operators[256] = "";
    bool is_address[256]; // 0: value, 1: address
    memset(is_address, 0, sizeof(is_address));
    int64_t values[256];
    int values_count = 0;
    for (int i = 0; expression[i]; i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '&' || expression[i] == '|' || expression[i] == '%') {
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
                char* first_operand_value = evaluate(first_operand, variables, error_flag, address);
                char* second_operand_value = evaluate(second_operand, variables, error_flag, address);
                if (*error_flag == 1) {
                    return "";
                }
                i = k;
                is_address[values_count] = 1;
                values[values_count++] = bxor(first_operand_value, second_operand_value, address);
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
                char* first_operand_value = evaluate(first_operand, variables, error_flag, address);
                char* second_operand_value = evaluate(second_operand, variables, error_flag, address);
                if (*error_flag == 1) {
                    return "";
                }
                i = k;
                is_address[values_count] = 1;
                values[values_count++] = ls(first_operand_value, second_operand_value, address);
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
                char* first_operand_value = evaluate(first_operand, variables, error_flag, address);
                char* second_operand_value = evaluate(second_operand, variables, error_flag, address);
                if (*error_flag == 1) {
                    return "";
                }
                i = k;
                is_address[values_count] = 1;
                values[values_count++] = rs(first_operand_value, second_operand_value, address);
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
                char* first_operand_value = evaluate(first_operand, variables, error_flag, address);
                char* second_operand_value = evaluate(second_operand, variables, error_flag, address);
                if (*error_flag == 1) {
                    return "";
                }
                i = k;
                is_address[values_count] = 1;
                values[values_count++] = lr(first_operand_value, second_operand_value, address);
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
                char* first_operand_value = evaluate(first_operand, variables, error_flag, address);
                char* second_operand_value = evaluate(second_operand, variables, error_flag, address);
                if (*error_flag == 1) {
                    return "";
                }
                i = k;
                is_address[values_count] = 1;
                values[values_count++] = rr(first_operand_value, second_operand_value, address);
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
                char* first_operand_value = evaluate(first_operand, variables, error_flag, address);
                if (*error_flag == 1) {
                    return "";
                }
                i = j;
                is_address[values_count] = 1;
                values[values_count++] = bnot(first_operand_value, address);
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
                char* result = evaluate(first_operand, variables, error_flag, address);
                is_address[values_count] = (result[0] == '%' ? 1 : 0);
                values[values_count++] = string_to_value(result);
                if (*error_flag == 1) {
                    return "";
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
                return "";
            }
            if (isKeyword(variable_name)) {
                // Check the next character that is not a space is '('
                int l = i + 1;
                for (; expression[l]; l++) {
                    if (expression[l] != ' ') break;
                }
                if (expression[l] != '(') {
                    *error_flag = 1;
                    return "";
                }
                continue;
            }
            is_address[values_count] = 1;
            if(is_defined(variables, variable_name) == 0){
                *error_flag = 1;
                return "";
            }
            values[values_count++] = address_of(variable_name, address);
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
            is_address[values_count] = 0;
            values[values_count++] = atoi(number);
        }
        else if(expression[i] != ' '){
            *error_flag = true;
            return "";
        }
    }
    if (values_count - 1 != (int)strlen(sign_operators)) {
        *error_flag = true;
        return "";
    }
    // Do all *, /, % operations
    for (int i = 0; i < (int)strlen(sign_operators); i++) {
        if (sign_operators[i] == '*') {
            values[i] = multiple(value_to_string(values[i], is_address[i]), value_to_string(values[i + 1], is_address[i + 1]), address);
            is_address[i] = 1;
            for (int j = i + 1; j < values_count - 1; j++) {
                is_address[j] = is_address[j + 1];
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
            values[i] = divide(value_to_string(values[i], is_address[i]), value_to_string(values[i + 1], is_address[i + 1]), address);
            is_address[i] = 1;
            for (int j = i + 1; j < values_count - 1; j++) {
                is_address[j] = is_address[j + 1];
                values[j] = values[j + 1];
            }
            values_count--;
            for (int j = i; j < (int)strlen(sign_operators) - 1; j++) {
                sign_operators[j] = sign_operators[j + 1];
            }
            sign_operators[strlen(sign_operators) - 1] = 0;
            i--;
        }
        if (sign_operators[i] == '%') {
            values[i] = modulo(value_to_string(values[i], is_address[i]), value_to_string(values[i + 1], is_address[i + 1]), address);
            is_address[i] = 1;
            for (int j = i + 1; j < values_count - 1; j++) {
                is_address[j] = is_address[j + 1];
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
            values[i] = sum(value_to_string(values[i], is_address[i]), value_to_string(values[i + 1], is_address[i + 1]), address);
            is_address[i] = 1;
            for (int j = i + 1; j < values_count - 1; j++) {
                is_address[j] = is_address[j + 1];
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
            values[i] = substract(value_to_string(values[i], is_address[i]), value_to_string(values[i + 1], is_address[i + 1]), address);
            is_address[i] = 1;
            for (int j = i + 1; j < values_count - 1; j++) {
                is_address[j] = is_address[j + 1];
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
            values[i] = band(value_to_string(values[i], is_address[i]), value_to_string(values[i + 1], is_address[i + 1]), address);
            is_address[i] = 1;
            for (int j = i + 1; j < values_count - 1; j++) {
                is_address[j] = is_address[j + 1];
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
            values[i] = bor(value_to_string(values[i], is_address[i]), value_to_string(values[i + 1], is_address[i + 1]), address);
            is_address[i] = 1;
            for (int j = i + 1; j < values_count - 1; j++) {
                is_address[j] = is_address[j + 1];
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
    return value_to_string(values[0], is_address[0]);
}
