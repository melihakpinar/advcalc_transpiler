#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define P 61
#define N 1000003


/*
* This struct is used to check if a variable is defined.
*/
typedef struct Hashmap{
    int64_t* container;
    int size;
} hashmap;

/*
* This function is used to construct the hashmap.
* @param size: The size of the hashmap.
* @return: The constructed hashmap.
*/
hashmap* map_construct(int size);

/*
* This function is used to hash the variable name.
* @param string: The variable name.
* @return: The hash value of the variable name.
*/
int hash(char* string);

/*
* This function is used to insert a variable into the hashmap.
* @param map: The hashmap to store the variables.
* @param variable: The variable name.
*/
void define_variable(hashmap* map, char* variable);

/*
* This function is used to check if a variable is defined.
* @param map: The hashmap to store the variables.
* @param variable: The variable name.
* @return: 1 if the variable is defined, 0 otherwise.
*/
int is_defined(hashmap* map, char* variable);

#endif
