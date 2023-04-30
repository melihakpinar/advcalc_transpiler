#ifndef PRINTER_H
#define PRINTER_H

#include <stdio.h>
#include <string.h>


void open_file(char* filename);

void close_file();

void write_begin();

void write_end();

void allocate(char* variable);

void assign(char* variable, char* value);

void print(char* address);

void operation(int address, char* left, char* right, char* op);

void load(int address, char* variable);

void generate_output_filename(char* filename, char* output_filename);

void delete_output_file(char* filename);

#endif