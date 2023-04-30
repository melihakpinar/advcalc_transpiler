#include "math.h"


int sum(char* a, char* b, int* address){
    operation((*address), a, b, "add");
    return (*address)++;
}

int multiple(char* a, char* b, int* address){
    operation((*address), a, b, "mul");
    return (*address)++;
}

int substract(char* a, char* b, int* address){
    operation((*address), a, b, "sub");
    return (*address)++;
}

int divide(char* a, char* b, int* address){
    operation((*address), a, b, "adiv");
    return (*address)++;
}

int modulo(char* a, char* b, int* address){
    int division = divide(a, b, address);
    char division_address[10];
    sprintf(division_address, "%%%d", division);
    int multiplication = multiple(b, division_address, address);
    char multiplication_address[10];
    sprintf(multiplication_address, "%%%d", multiplication);
    return substract(a, multiplication_address, address);
}

int band(char* a, char* b, int* address){
    operation((*address), a, b, "and");
    return (*address)++;
}

int bor(char* a, char* b, int* address){
    operation((*address), a, b, "or");
    return (*address)++;
}

int bxor(char* a, char* b, int* address){
    operation((*address), a, b, "xor");
    return (*address)++;
}

int ls(char* a, char* i, int* address){
    operation((*address), a, i, "shl");
    return (*address)++;
}

int rs(char* a, char* i, int* address){
    operation((*address), a, i, "ashr");
    return (*address)++;
}

int lr(char* a, char* b, int* address){
    int mod = modulo(b, "32", address);
    char mod_address[10];
    sprintf(mod_address, "%%%d", mod);
    int left = ls(a, mod_address, address);
    char left_address[10];
    sprintf(left_address, "%%%d", left);
    int sub = substract("32", mod_address, address);
    char sub_address[10];
    sprintf(sub_address, "%%%d", sub);
    int right = rs(a, sub_address, address);
    char right_address[10];
    sprintf(right_address, "%%%d", right);
    return bor(left_address, right_address, address);
}

int rr(char* a, char* b, int* address){
    int mod = modulo(b, "32", address);
    char mod_address[10];
    sprintf(mod_address, "%%%d", mod);
    int right = rs(a, mod_address, address);
    char right_address[10];
    sprintf(right_address, "%%%d", right);
    int sub = substract("32", mod_address, address);
    char sub_address[10];
    sprintf(sub_address, "%%%d", sub);
    int left = ls(a, sub_address, address);
    char left_address[10];
    sprintf(left_address, "%%%d", left);
    return bor(left_address, right_address, address);
}

int bnot(char* a, int* address){
    return bxor(a, "-1", address);
}

int address_of(char *variable, int* address){
    load((*address), variable);
    return (*address)++;
}