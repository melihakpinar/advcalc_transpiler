#include "operators.h"

int sum(int a, int b){
    return a + b;
}

int multiple(int a, int b){
    return a * b;
}

int substract(int a, int b){
    return a - b;
}

int band(int a, int b){
    return a & b;
}

int bor(int a, int b){
    return a | b;
}

int bxor(int a, int b){
    return a ^ b;
}

int ls(int a, int i){
    return a << i;
}

int rs(int a, int i){
    return a >> i;
}

int lr(int a, int i){
    i %= 64ll;
    while(i--){
        if(a & (1ll << 63)) a = (a << 1) | 1;
        else a = a << 1;
    }
    return a;
}

int rr(int a, int i){
    i %= 64ll;
    while(i--){
        if(a & 1) a = (a >> 1) | (1ll << 63);
        else a = a >> 1;
    }
    return a;
}

int bnot(int a){
    return -1ll ^ a;
}
