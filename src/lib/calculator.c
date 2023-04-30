#include "calculator.h"


void calculator(char* input){
    static hashmap* map;
    if(map == NULL){
        map = map_construct(N);
    }

    if(isBlank(input)){
        return;
    }

    bool error_flag = false;
    bool is_assignment_flag = isAssignment(input, &error_flag);

    if(error_flag){
        printf("Error!\n");
        return;
    }

    char expression[300] = "";
    char variable[300] = "";

    if(is_assignment_flag){
        int assignment_index = find_assignment_sign(input);
        copyVariable(variable, input, assignment_index);
        strncpy(expression, input + assignment_index + 1, strlen(input) - assignment_index - 1);
    }
    else{
        strncpy(expression, input, strlen(input));
    }

    if(!areBracketsBalanced(expression)){
        printf("Error!\n");
        return;
    }

    int64_t value = evaluate(expression, map, &error_flag);

    if(error_flag){
        printf("Error!\n");
        return;
    }

    if(is_assignment_flag){
        map_assign(map, variable, value);
    }
    else{
        printf("%ld\n", value);
    }
}

int find_assignment_sign(char* input){
    for(int i = 0; i < (int)strlen(input); i++){
        if(input[i] == '='){
            return i;
        }
    }
    return -1;
}

bool isBlank(char* input){
    for(int i = 0; i < (int)strlen(input); i++){
        if(input[i] != ' '){
            return false;
        }
    }
    return true;
}

void copyVariable(char* variable, char* input, int size){
    int i = 0, j = 0;
    while(input[i] == ' '){
        i++;
    }
    for(; i < size && input[i] && input[i] != ' '; i++){
        variable[j++] = input[i];
    }
}
