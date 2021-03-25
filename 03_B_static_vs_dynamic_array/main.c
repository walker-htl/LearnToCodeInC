#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 5

int main() {
    // int pointer which points to the heap
    int* dynArrPointer = NULL;
    printf("dynArrPointer = %p\n", dynArrPointer);
    // malloc() allocate the memory for 5 integers
    // containing garbage values
    dynArrPointer = (int*)malloc(ARRAY_SIZE * sizeof(int)); // 5*4bytes = 20 bytes
    int* rememberStartPointer = dynArrPointer;

    *dynArrPointer = 4;
    dynArrPointer++;
    *dynArrPointer = 3;
    *++dynArrPointer = 2;
    *++dynArrPointer = 1;
    dynArrPointer++;
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
