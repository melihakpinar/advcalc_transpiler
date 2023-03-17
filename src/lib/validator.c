#include "validator.h"

#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool is_assignment(char* str, bool* error_flag){
    int equals_cnt = 0;
    int equal_index = 0;
    for(int i = 0; i < strlen(str); i++){
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
    char* variable;
    strncpy(variable, str, equal_index);
    if(!is_variable(variable)){
        *error_flag = true;
        return false;
    }
    return true;
}

bool is_variable(char* str){
    int l = 0;
    int r = strlen(str) - 1;
    while(l < r && str[l] == ' ') l++;
    while(l < r && str[r] == ' ') r--;
    if(l == r) return false;
    for(int i = l; i <= r; i++){
        if(!isalpha(str[i])) 
            return false;
    }
    *(str + r + 1) = '\0';
    char** operations = {"xor", "ls", "rs", "lr", "rr", "not"};
    for(int i = 0; i < 6; i++){
        if(is_equal(str + l, operations[i]))
            return false;
    }
    return true;
}

bool is_paranthesis_valid(char* str, bool* error_flag){
    int paranthesis = 0;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == '(')
            paranthesis++;
        else if(str[i] == ')')
            paranthesis--;
        if(paranthesis < 0)
            return false;
    }
    return paranthesis == 0;
}

bool is_equal(char* str1, char* str2){
    if(strlen(str1) != strlen(str2))
        return false;
    for(int i = 0; i < strlen(str1); i++){
        if(str1[i] != str2[i])
            return false;
    }
    return true;
}
