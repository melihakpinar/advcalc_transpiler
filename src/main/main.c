#include <stdio.h>
#include "operators.h"

int32_t main() {
    // while(1){
    //     printf(">");
    //     char input[1000];
    //     fgets(input, 1000, stdin);
    //     parse(input);
    // }

    printf("asd\n");
    printf("sum :%lld\n", sum(3, 5));
    printf("multiple: %lld\n", multiple(3, 5));
    printf("substract: %lld\n", substract(3, 5));
    printf("band: %lld\n", band(3, 5));
    printf("bor: %lld\n", bor(3, 5));
    printf("bxor: %lld\n", bxor(3, 5));
    printf("ls: %lld\n", ls(3, 65));
    printf("rs: %lld\n", rs(5, 1));
    printf("lr: %lld\n", lr(3, 1));
    printf("rr: %lld\n", rr(3, 1));
    printf("bnot: %lld\n", bnot(1ll<<63));
    
    return 0;
}
