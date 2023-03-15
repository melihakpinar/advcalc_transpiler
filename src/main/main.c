#include <stdio.h>
#include <string.h>
#include "lib/math.h"

int32_t main() {
    while(1){
        printf(">");
        char input[300];
        fgets(input, 300, stdin);
        input[strlen(input) - 1] = '\0';
        
        // TODO: evaluate input
    }
    return 0;
}
