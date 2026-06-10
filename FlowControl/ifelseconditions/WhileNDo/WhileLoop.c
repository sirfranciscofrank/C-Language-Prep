#include <stdio.h>

int main(void){
        int initial_value;
        initial_value = 0;

        // 1. Print start before the loop begins
        printf("start\n");

        while(initial_value != 10){

                initial_value++;

                // We no longer need the if/else here 
                // because start is already printed
                printf("%d \n", initial_value);
        }

        // 2. Print end after the loop completes
        printf("end\n");

        return 0;
}

