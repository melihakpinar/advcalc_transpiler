#include "calculator.h"


void calculator(char* line, int line_number, char* output_filename){
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
        printf("Error 1 on line %d!\n", line_number);
        close_file();
        delete_output_file(output_filename);
        exit(0);
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
        printf("Error 2 on line %d!\n", line_number);
        close_file();
        delete_output_file(output_filename);
        exit(0);
    }

    char* value = evaluate(expression, map, &error_flag);

    if(error_flag){
        printf("Error 3 on line %d!\n", line_number);
        close_file();
        delete_output_file(output_filename);
        exit(0);
    }

    if(is_assignment_flag){
        if (is_defined(map, variable) == 0){
            allocate(variable);
        }
        assign(variable, value);
        define_variable(map, variable);
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
