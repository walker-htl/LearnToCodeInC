#include <stdio.h>
#include <stdlib.h>

void testPointer();
void inc1(int i) {
    i++;
}

void inc2(int* i){
    (*i)++;
}

void testPointerOfPointer();

void allocate(int* i) {
    // Be aware: here we produce a memory hole (leak!)
    i = malloc(sizeof(int));
}

void allocate2(int** i) {
    *i = malloc(sizeof(int));
}

int main() {
    testPointer();
    printf("\n");
    testPointerOfPointer();

    return 0;
}

void testPointer()
{
    int i = 0;
    inc1(i);
    printf("After calling inc1(0) i = %d\n", i);

    // in this method we increment the value at the address we pass as parameter (argument)
    inc2(&i);
    printf("After calling inc2(0) i = %d\n", i);
}

void testPointerOfPointer()
{
    int* pi = NULL;
    allocate(pi);
    printf("We allocated space for one integer but our pointer shows: %p\n", pi);

    allocate2(&pi);
    printf("We allocated space for one integer! You reach this space on address: %p\n", pi);
}
