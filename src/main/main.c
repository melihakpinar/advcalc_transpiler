#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "lib/calculator.h"
#include "lib/printer.h"


void generate_output_filename(char* filename, char* output_filename){
    int i = strlen(filename) - 1;
    while(filename[i] != '.'){
        i--;
    }
    strncpy(output_filename, filename, i);
    strncpy(output_filename + i, ".ll\0", 4);
}

int main(int argc, char** argv) {
    if(argc < 2){
        return 0;
    }
    char filename[256];
    strcpy(filename, argv[1]);
    FILE* input_file = fopen(filename, "r");
    if(input_file == NULL){
        return 0;
    }
    char output_filename[256];
    generate_output_filename(filename, output_filename);
    open_file(output_filename);
    char input[300];
    int line_number = 1;
    bool error_flag = false;
    while(fgets(input, 300, input_file) != NULL){
        if(input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';
        error_flag |= calculator(input, line_number++);
    }
    close_file();
    fclose(input_file);
    if(error_flag)
        remove(output_filename);
    return 0;
}
