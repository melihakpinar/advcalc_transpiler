#include <string.h>
#include <stdint.h>

#include "lib/calculator.h"

int32_t main(void) {
    while(1){
        printf("> ");
        char input[300];
        char* tmp = fgets(input, 300, stdin);
        if(tmp == NULL)
            break;
        input[strlen(input) - 1] = '\0';
        calculator(input);
    }
    return 0;
}
