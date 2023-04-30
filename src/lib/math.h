#ifndef MATH_H
#define MATH_H

#include "printer.h"


/*
* @param: a: char*
* @param: b: char*
* @return: sum of a and b
*/
int sum(char* a, char* b);

/*
* @param: a: char*
* @param: b: char*
* @return: multiplication of a and b
*/
int multiple(char* a, char* b);

/*
* @param: a: char*
* @param: b: char*
* @return: substraction of a and b
*/
int substract(char* a, char* b);

/*
* @param: a: char*
* @param: b: char*
* @return: division of a and b
*/
int divide(char* a, char* b);

/*
* @param: a: int64_t
* @param: b: int64_t
* @return: modulo of a and b
*/
int modulo(char* a, char* b);

/*
* @param: a: char*
* @param: b: char*
* @return: binary and of a and b
*/
int band(char* a, char* b);

/*
* @param: a: char*
* @param: b: char*
* @return: binary or of a and b
*/
int bor(char* a, char* b);

/*
* @param: a: char*
* @param: b: char*
* @return: binary xor of a and b
*/
int bxor(char* a, char* b);

/*
* @param: a: char*
* @param: i: char*
* @return: left shift of a by i
*/
int ls(char* a, char* i);

/*
* @param: a: char*
* @param: i: char*
* @return: right shift of a by i
*/
int rs(char* a, char* i);

/*
* @param: a: char*
* @param: i: char*
* @return: binary left rotate of a by i
*/
int lr(char* a, char* b);

/*
* @param: a: char*
* @param: i: char*
* @return: binary right rotate of a by i
*/
int rr(char* a, char* b);

/*
* @param: a: char*
* @return: bitwise complement of a
*/
int bnot(char* a);

int address_of(char* variable);

#endif
