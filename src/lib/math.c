#include "math.h"

#include "printer.h"

int sum(char* a, char* b){
    operation(ADDRESS, a, b, "add");
    return ADDRESS++;
}

int multiple(char* a, char* b){
    operation(ADDRESS, a, b, "mul");
    return ADDRESS++;
}

int substract(char* a, char* b){
    operation(ADDRESS, a, b, "sub");
    return ADDRESS++;
}

int divide(char* a, char* b){
    operation(ADDRESS, a, b, "adiv");
    return ADDRESS++;
}

int modulo(char* a, char* b){
    int division = divide(a, b);
    char division_address[10];
    sprintf(division_address, "%%%d", division);
    int multiplication = multiple(b, division_address);
    char multiplication_address[10];
    sprintf(multiplication_address, "%%%d", multiplication);
    return substract(a, multiplication_address);
}

int band(char* a, char* b){
    operation(ADDRESS, a, b, "and");
    return ADDRESS++;
}

int bor(char* a, char* b){
    operation(ADDRESS, a, b, "or");
    return ADDRESS++;
}

int bxor(char* a, char* b){
    operation(ADDRESS, a, b, "xor");
    return ADDRESS++;
}

int ls(char* a, char* i){
    operation(ADDRESS, a, i, "shl");
    return ADDRESS++;
}

int rs(char* a, char* i){
    operation(ADDRESS, a, i, "ashr");
    return ADDRESS++;
}

int lr(char* a, char* b){
    int mod = modulo(b, "32");
    char mod_address[10];
    sprintf(mod_address, "%%%d", mod);
    int left = ls(a, mod_address);
    char left_address[10];
    sprintf(left_address, "%%%d", left);
    int sub = substract("32", mod_address);
    char sub_address[10];
    sprintf(sub_address, "%%%d", sub);
    int right = rs(a, sub_address);
    char right_address[10];
    sprintf(right_address, "%%%d", right);
    return bor(left_address, right_address);
}

int rr(char* a, char* b){
    int mod = modulo(b, "32");
    char mod_address[10];
    sprintf(mod_address, "%%%d", mod);
    int right = rs(a, mod_address);
    char right_address[10];
    sprintf(right_address, "%%%d", right);
    int sub = substract("32", mod_address);
    char sub_address[10];
    sprintf(sub_address, "%%%d", sub);
    int left = ls(a, sub_address);
    char left_address[10];
    sprintf(left_address, "%%%d", left);
    return bor(left_address, right_address);
}

int bnot(char* a){
    return bxor(a, "-1");
}
