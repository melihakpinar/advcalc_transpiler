#ifndef PRINTER_H
#define PRINTER_H

#include <stdio.h>


int ADDRESS = 1;
FILE *output_file;

void open_file(char* filename);

void close_file();

void write_begin();

void write_end();

void allocate(char* variable);

void assign(char* variable, char* value);

void print(char* address);

void operation(int address, char* left, char* right, char* op);

#endif