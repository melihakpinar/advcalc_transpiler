#include <string.h>
#include <stdint.h>

#include "lib/calculator.h"

int32_t main() {
    while(1){
        printf("> ");
        char input[300];
        fgets(input, 300, stdin);
        if(strlen(input) == 0)
            break;
        input[strlen(input) - 1] = '\0';
        calculator(input);
    }
    return 0;
}
