#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdlib.h>
#include <string.h>

#define P 61
#define N 1000003

typedef struct Hashmap{
    int* container;
    int size;
} hashmap;

hashmap* map_construct(int size);

int hash(char* string);

void map_assign(hashmap* map, char* variable, int value);

int map_get(hashmap* map, char* variable);

#endif
