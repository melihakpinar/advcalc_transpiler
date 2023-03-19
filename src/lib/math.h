#ifndef MATH_H
#define MATH_H

/*
* @param: a: int
* @param: b: int
* @return: sum of a and b
*/
int sum(int a, int b);

/*
* @param: a: int
* @param: b: int
* @return: multiplication of a and b
*/
int multiple(int a, int b);

/*
* @param: a: int
* @param: b: int
* @return: substraction of a and b
*/
int substract(int a, int b);

/*
* @param: a: int
* @param: b: int
* @return: binary and of a and b
*/
int band(int a, int b);

/*
* @param: a: int
* @param: b: int
* @return: binary or of a and b
*/
int bor(int a, int b);

/*
* @param: a: int
* @param: b: int
* @return: binary xor of a and b
*/
int bxor(int a, int b);

/*
* @param: a: int
* @param: i: int
* @return: left shift of a by i
*/
int ls(int a, int i);

/*
* @param: a: int
* @param: i: int
* @return: right shift of a by i
*/
int rs(int a, int i);

/*
* @param: a: int
* @param: i: int
* @return: binary left rotate of a by i
*/
int lr(int a, int i);

/*
* @param: a: int
* @param: i: int
* @return: binary right rotate of a by i
*/
int rr(int a, int i);

/*
* @param: a: int
* @return: bitwise complement of a
*/
int bnot(int a);

#endif
