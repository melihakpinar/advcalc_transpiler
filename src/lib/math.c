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
    while(i--){
        if(a & (1ll << 63)) a = (a << 1) | 1;
        else a = a << 1;
    }
    return a;
}

int64_t rr(int64_t a, int64_t i){
    i %= 64ll;
    while(i--){
        if(a & 1) a = (a >> 1) | (1ll << 63);
        else a = a >> 1;
    }
    return a;
}

int64_t bnot(int64_t a){
    return -1ll ^ a;
}
