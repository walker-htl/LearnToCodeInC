#include <stdio.h>

void weKnowThisAlready(char *pointer);
void whatHappensToNumbers(int *pointer);
void whatHappensLongs(long *pointer);

int main() {
    char text[6] = "Hello";
    weKnowThisAlready(text);

    int numbers[10] = {0, 1, 2, 3, 4};
    whatHappensToNumbers(numbers);

    long longNumbers[10] = {0, 1, 2, 3, 4};
    whatHappensLongs(longNumbers);

    return 0;
}

void weKnowThisAlready(char *pointer) {
    printf("1 Byte pro Element\n");
    while (*pointer != '\0') {
        printf("%p -> %c\n", pointer, *pointer);
        pointer++;
    }

    printf("\n");
}

void whatHappensToNumbers(int *pointer) {
    printf("4 Byte pro Element\n");
    for (int i = 0; i < 5; i++) {
        printf("%p -> %d\n", pointer, *pointer);
        pointer++;
    }

    printf("\n");
}

void whatHappensLongs(long *pointer) {
    printf("8 Byte pro Element\n");
    for (int i = 0; i < 5; i++) {
        printf("%p -> %ld\n", pointer, *pointer);
        pointer++;
    }

    printf("\n");
}