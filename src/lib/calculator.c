#include "calculator.h"

void calculator(char* input){
    static hashmap* map;
    if(map == NULL){
        map = map_construct(N);
    }

    remove_comments(input);

    bool error_flag = false;
    bool is_assignment_flag = is_assignment(input, &error_flag);

    if(error_flag){
        printf("Error!\n");
        return;
    }

    char* expression = "";
    char* variable = "";
    strncpy(expression, input, strlen(input));

    if(is_assignment_flag){
        int assignment_index = find_assignment_sign(input);
        strncpy(variable, input, assignment_index);
        strncpy(expression, input + assignment_index + 1, strlen(input) - assignment_index - 1);
    }

    int value = 0; // TODO: call evaluator here with expression

    if(is_assignment_flag){
        map_assign(map, variable, value);
    }
    else{
        printf("%d\n", value);
    }
}

int find_assignment_sign(char* input){
    for(int i = 0; i < strlen(input); i++){
        if(input[i] == '='){
            return i;
        }
    }
    return -1;
}

void remove_comments(char* input){
    for(int i = 0; i < strlen(input); i++){
        if(input[i] == '%'){
            input[i] = '\0';
            return;
        }
    }
}
