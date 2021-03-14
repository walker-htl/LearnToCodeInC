#include <stdio.h>

int calculationByValue(int value) {
    int result = 2*value;

    return result;
}

void calculationByReference(int value, int* result) {
    *result = 2*value;
}

char* returnTheText() {
    return "Hello";
}

char* returnALocalVariable() {
    char expression[10] = "Impossible";

    return expression;
}

void changeAnnToPat(char* pointToArray) {
    pointToArray += 6;
    *pointToArray = 'P';
    *++pointToArray = 'a';
    *++pointToArray = 't';
}

int main() {
    // simple example for call by value
    printf("\n--------- call by value ------------\n");
    int a = 14;
    int result = calculationByValue(a);
    printf("calculationByValue(%d) = %d\n", a, result);

    // simple example for call by reference
    printf("\n-------- call by reference ---------\n");
    a = 16;
    int *resultPointer=&result;
    calculationByReference(a, resultPointer);
    printf("calculationByReference(%d, %p) = %d\n", a, resultPointer, *resultPointer);

    printf("\n--------- return a string ----------\n");
    printf("Simple text = %s\n", returnTheText());

    printf("\n-------- Not working at all --------\n");
    // Address of stack memory associated with local variable 'name' returned
    printf("Simple text = %s\n", returnALocalVariable());

    printf("\n--------- Works but is bad ---------\n");
    char name[10] = "Hello Ann";
    printf("Before the change = %s\n", name);
    changeAnnToPat(name);
    printf("After the change  = %s\n", name);


    return 0;
}

