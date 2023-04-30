#include "calculator.h"

void calculator(char* line, int line_number){
    static hashmap* map;
    if(map == NULL){
        map = map_construct(N);
    }

    if(isBlank(line)){
        return;
    }

    bool error_flag = false;
    bool is_assignment_flag = isAssignment(line, &error_flag);

    if(error_flag){
        printf("Error on line %d!\n", line_number);
        return;
    }

    char expression[300] = "";
    char variable[300] = "";

    if(is_assignment_flag){
        int assignment_index = find_assignment_sign(line);
        copyVariable(variable, line, assignment_index);
        strncpy(expression, line + assignment_index + 1, strlen(line) - assignment_index - 1);
    }
    else{
        strncpy(expression, line, strlen(line));
    }

    if(!areBracketsBalanced(expression)){
        printf("Error on line %d!\n", line_number);
        return;
    }

    char* value = evaluate(expression, map, &error_flag);

    if(error_flag){
        printf("Error on line %d!\n", line_number);
        return;
    }

    if(is_assignment_flag){
        assign(variable, value);
    }
    else{
        print(value);
    }
}

int find_assignment_sign(char* line){
    for(int i = 0; i < (int)strlen(line); i++){
        if(line[i] == '='){
            return i;
        }
    }
    return -1;
}

bool isBlank(char* line){
    for(int i = 0; i < (int)strlen(line); i++){
        if(line[i] != ' '){
            return false;
        }
    }
    return true;
}

void copyVariable(char* variable, char* line, int size){
    int i = 0, j = 0;
    while(line[i] == ' '){
        i++;
    }
    for(; i < size && line[i] && line[i] != ' '; i++){
        variable[j++] = line[i];
    }
}
