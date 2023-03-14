#include <stdio.h>
#include "parser.h"

int main() {
    while(1){
        printf(">");
        char input[1000];
        fgets(input, 1000, stdin);
        parse(input);
    }
    return 0;
}
