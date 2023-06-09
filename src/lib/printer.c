#include "printer.h"


FILE *output_file;

void open_file(char* filename){
    output_file = fopen(filename, "w");
    write_begin();
}

void close_file(void){
    write_end();
    fclose(output_file);
}

void write_begin(void){
    fprintf(output_file, "; ModuleID = ’advcalc2ir’\n");
    fprintf(output_file, "declare i32 @printf(i8*, ...)\n");
    fprintf(output_file, "@print.str = constant [4 x i8] c\"%%d\\0A\\00\"\n");
    fprintf(output_file, "\n");
    fprintf(output_file, "define i32 @main() {\n");
}

void write_end(void){
    fprintf(output_file, "\tret i32 0\n");
    fprintf(output_file, "}\n");
}

void allocate(char* variable){
    fprintf(output_file, "\t%%%s = alloca i32\n", variable);
}

void assign(char* variable, char* value){
    fprintf(output_file, "\tstore i32 %s, i32* %%%s\n", value, variable);
}

void print(char* value){
    fprintf(output_file, "\tcall i32 (i8*, ...) @printf(i8* getelementptr ([4 x i8], [4 x i8]* @print.str, i32 0, i32 0), i32 %s)\n", value);
}

void operation(int address, char* left, char* right, char* op){
    fprintf(output_file, "\t%%%d = %s i32 %s, %s\n", address, op, left, right);
}

void load(int address, char *variable){
    fprintf(output_file, "\t%%%d = load i32, i32* %%%s\n", address, variable);
}
