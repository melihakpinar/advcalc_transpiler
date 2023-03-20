#ifndef MATH_H
#define MATH_H

#include <stdint.h>

/*
* @param: a: int64_t
* @param: b: int64_t
* @return: sum of a and b
*/
int64_t sum(int64_t a, int64_t b);

/*
* @param: a: int64_t
* @param: b: int64_t
* @return: multiplication of a and b
*/
int64_t multiple(int64_t a, int64_t b);

/*
* @param: a: int64_t
* @param: b: int64_t
* @return: substraction of a and b
*/
int64_t substract(int64_t a, int64_t b);

/*
* @param: a: int64_t
* @param: b: int64_t
* @return: binary and of a and b
*/
int64_t band(int64_t a, int64_t b);

/*
* @param: a: int64_t
* @param: b: int64_t
* @return: binary or of a and b
*/
int64_t bor(int64_t a, int64_t b);

/*
* @param: a: int64_t
* @param: b: int64_t
* @return: binary xor of a and b
*/
int64_t bxor(int64_t a, int64_t b);

/*
* @param: a: int64_t
* @param: i: int64_t
* @return: left shift of a by i
*/
int64_t ls(int64_t a, int64_t i);

/*
* @param: a: int64_t
* @param: i: int64_t
* @return: right shift of a by i
*/
int64_t rs(int64_t a, int64_t i);

/*
* @param: a: int64_t
* @param: i: int64_t
* @return: binary left rotate of a by i
*/
int64_t lr(int64_t a, int64_t i);

/*
* @param: a: int64_t
* @param: i: int64_t
* @return: binary right rotate of a by i
*/
int64_t rr(int64_t a, int64_t i);

/*
* @param: a: int64_t
* @return: bitwise complement of a
*/
int64_t bnot(int64_t a);

#endif
