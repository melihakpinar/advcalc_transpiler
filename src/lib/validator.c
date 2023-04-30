#include "validator.h"


bool isAssignment(char* str, bool* error_flag){
    int equals_cnt = 0;
    int equal_index = 0;
    for(int i = 0; i < (int)strlen(str); i++){
        if(str[i] == '='){
            equals_cnt++;
            equal_index = i;
        }
        if(equals_cnt > 1){
            *error_flag = true;
            return false;
        }
    }
    if(equals_cnt == 0)
        return false;
    char variable[300] = "";
    strncpy(variable, str, equal_index);
    if(!isVariable(variable) || isKeyword(variable)){
        *error_flag = true;
        return false;
    }
    return true;
}

bool isVariable(char* str){
    int l = 0;
    int r = strlen(str) - 1;
    while(l < r && str[l] == ' ') l++;
    while(l < r && str[r] == ' ') r--;
    for(int i = l; i <= r; i++){
        if(!isalpha(str[i])) 
            return false;
    }
    *(str + r + 1) = '\0';
    return true;
}

bool isKeyword(char* str){
    char* keywords[6] = {"xor", "ls", "rs", "lr", "rr", "not"};
    for(int i = 0; i < 6; i++){
        if(isEqual(str, keywords[i]))
            return true;
    }
    return false;
}

bool areBracketsBalanced(char* str){
    int paranthesis = 0;
    for(int i = 0; i < (int)strlen(str); i++){
        if(str[i] == '(')
            paranthesis++;
        else if(str[i] == ')')
            paranthesis--;
        if(paranthesis < 0)
            return false;
    }
    return paranthesis == 0;
}

bool isEqual(char* str1, char* str2){
    if(strlen(str1) != strlen(str2))
        return false;
    for(int i = 0; i < (int)strlen(str1); i++){
        if(str1[i] != str2[i])
            return false;
    }
    return true;
}

bool isOperatorOrderCorrect(char* expression) {
    // There should not be two operators in a row (ignoring spaces)
    // Operators are +, -, *, &, |
    // If the order is not correct, return 0
    // If the order is correct, return 1
    for (int i = 0; expression[i]; i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '&' || expression[i] == '|') {
            for (int j = i + 1; expression[j]; j++) {
                if (expression[j] == ' ') {
                    continue;
                } else if (expression[j] == '+' || expression[j] == '-' || expression[j] == '*' || expression[j] == '&' || expression[j] == '|') {
                    return 0;
                } else {
                    break;
                }
            }
        }
    }
    return 1;
}

bool doesExpressionStartOrEndWithOperator(char* expression) {
    for (int i = 0; expression[i]; i++) {
        if (expression[i] == ' ') {
            continue;
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '&' || expression[i] == '|') {
            return 1;
        } else {
            break;
        }
    }
    for (int i = strlen(expression) - 1; i >= 0; i--) {
        if (expression[i] == ' ') {
            continue;
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '&' || expression[i] == '|') {
            return 1;
        } else {
            break;
        }
    }
    return 0;
}

bool isValid(char* expression) {
    bool validity = true;
    validity &= areBracketsBalanced(expression);
    validity &= isOperatorOrderCorrect(expression);
    validity &= !doesExpressionStartOrEndWithOperator(expression);
    return validity;
}
