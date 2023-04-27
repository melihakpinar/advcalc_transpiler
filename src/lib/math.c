#include "math.h"

int64_t sum(int64_t a, int64_t b){
    return a + b;
}

int64_t multiple(int64_t a, int64_t b){
    return a * b;
}

int64_t substract(int64_t a, int64_t b){
    return a - b;
}

int64_t divide(int64_t a, int64_t b){
    return a / b;
}

int64_t band(int64_t a, int64_t b){
    return a & b;
}

int64_t bor(int64_t a, int64_t b){
    return a | b;
}

int64_t bxor(int64_t a, int64_t b){
    return a ^ b;
}

int64_t ls(int64_t a, int64_t i){
    return a << i;
}

int64_t rs(int64_t a, int64_t i){
    return a >> i;
}

int64_t lr(int64_t a, int64_t i){
    i %= 64ll;
    return (a << i) | (a >> (64ll - i));
}

int64_t rr(int64_t a, int64_t i){
    i %= 64ll;
    return (a >> i) | (a << (64ll - i));
}

int64_t bnot(int64_t a){
    return -1ll ^ a;
}
