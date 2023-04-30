#ifndef PRINTER_H
#define PRINTER_H

#include <stdio.h>
#include <string.h>

/*
* This function opens the file with the given filename and writes the begining of the LLVM IR code.
* @param filename The name of the file to be opened.
*/
void open_file(char* filename);

/*
* This function writes end of the code and closes the file that was opened with the open_file function.
*/
void close_file();

/*
* This function writes the begining of the LLVM IR code.
*/
void write_begin();

/*
* This function writes the end of the LLVM IR code.
*/
void write_end();

/*
* This function writes the code for allocating a variable.
* @param variable The name of the variable to be allocated.
*/
void allocate(char* variable);

/*
* This function writes the code for assigning a value to a variable.
* @param variable The name of the variable to be assigned.
* @param value The value to be assigned to the variable.
*/
void assign(char* variable, char* value);

/*
* This function writes the code for printing a value.
* @param value The value to be printed.
*/
void print(char* address);

/*
* This function writes the code for an operation.
* @param address The address of the variable to store the result of the operation.
* @param left The left operand of the operation.
* @param right The right operand of the operation.
* @param op The operation to be performed.
*/
void operation(int address, char* left, char* right, char* op);

/*
* This function writes the code for loading a variable.
* @param address The address of the variable to store the result of the load.
* @param variable The name of the variable to be loaded.
*/
void load(int address, char* variable);


#endif