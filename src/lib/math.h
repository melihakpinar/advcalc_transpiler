#ifndef MATH_H
#define MATH_H

#include "printer.h"


/*
* @param: a: char*
* @param: b: char*
* @return: address of the result of the sum
*/
int sum(char* a, char* b, int* address);

/*
* @param: a: char*
* @param: b: char*
* @return: address of the result of the multiplication
*/
int multiple(char* a, char* b, int* address);

/*
* @param: a: char*
* @param: b: char*
* @return: address of the result of the substraction
*/
int substract(char* a, char* b, int* address);

/*
* @param: a: char*
* @param: b: char*
* @return: address of the result of the division
*/
int divide(char* a, char* b, int* address);

/*
* @param: a: int64_t
* @param: b: int64_t
* @return: address of the result of the modulo operation
*/
int modulo(char* a, char* b, int* address);

/*
* @param: a: char*
* @param: b: char*
* @return: address of the result of the binary and
*/
int band(char* a, char* b, int* address);

/*
* @param: a: char*
* @param: b: char*
* @return: address of the result of the binary or
*/
int bor(char* a, char* b, int* address);

/*
* @param: a: char*
* @param: b: char*
* @return: address of the result of the binary xor
*/
int bxor(char* a, char* b, int* address);

/*
* @param: a: char*
* @param: i: char*
* @return: address of the result of the binary left shift
*/
int ls(char* a, char* i, int* address);

/*
* @param: a: char*
* @param: i: char*
* @return: address of the result of the binary right shift
*/
int rs(char* a, char* i, int* address);

/*
* @param: a: char*
* @param: i: char*
* @return: address of the result of the binary left rotate
*/
int lr(char* a, char* b, int* address);

/*
* @param: a: char*
* @param: i: char*
* @return: address of the result of the binary right rotate
*/
int rr(char* a, char* b, int* address);

/*
* @param: a: char*
* @return: address of the result of the binary complement of a
*/
int bnot(char* a, int* address);

/*
* Load a variable into a register and return the address of the register
* @param: variable: char*
* @param: address: int*
* @return: address of the variable
*/
int address_of(char* variable, int* address);

#endif
