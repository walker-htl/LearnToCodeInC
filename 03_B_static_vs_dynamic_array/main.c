#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 5

int main() {
    // int pointer which should point to the heap!
    int* dynArrPointer = NULL;
    printf("dynArrPointer = %p\n", dynArrPointer);

    // malloc() allocate the memory for 5 integers
    // containing garbage values
    dynArrPointer = (int*)malloc(ARRAY_SIZE * sizeof(int)); // 5*4bytes = 20 bytes

    // don't loose the memory block start
    int* rememberStartPointer = dynArrPointer;

    // value 4 will be stored on first place of allocated space
    *dynArrPointer = 4;
    // one step forward in the allocated space
    dynArrPointer++;
    // value 3 will be stored on second place of allocated space
    *dynArrPointer = 3;
    // one step forward and assigning of value 2 on the third place
    *++dynArrPointer = 2;
    // same step as before
    *++dynArrPointer = 1;
    // on step
    dynArrPointer++;
    // last assignment
    *dynArrPointer = 0;

    // set pointer to the start position
    dynArrPointer = rememberStartPointer;

    // int array which points to the stack
    int statArr[ARRAY_SIZE] = {0, 1, 2, 3, 4};
    int* statArrPointer = statArr;

    printf("dynArrPointer points into the heap with following address %p\n", dynArrPointer);
    printf("statArr points into the stack with following address %p\n", statArr);
    printf("sizeof(int) = %lu\n", sizeof(int));
    printf("------------------------------------------------------------\n\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("dynArrPointer on address %p with value %d\n", dynArrPointer, *dynArrPointer);
        printf("statArr on address %p with value %d\n\n", statArrPointer, *statArrPointer);

        // pointer arithemtics for dynamic memory blocks and arrays
        dynArrPointer++;
        statArrPointer++;
    }

    // Deallocates memory previously allocated by malloc() function
    free(rememberStartPointer);
}
