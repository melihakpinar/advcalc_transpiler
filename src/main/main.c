#include <string.h>
#include <stdint.h>
#include <stdio.h>

#include "lib/calculator.h"
#include "lib/printer.h"


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
    while(fgets(input, 300, input_file) != NULL){
        if(input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';
        calculator(input, line_number++, output_filename);
    }
    close_file();
    return 0;
}
