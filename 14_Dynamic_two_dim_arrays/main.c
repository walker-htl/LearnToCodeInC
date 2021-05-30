#include <stdio.h>
#include <stdlib.h>

int main() {
    int **matrix;

    // allocate an array of ten int pointers
    matrix = malloc (sizeof ( int *) * 10);

    // allocate ten times an int array with 5 elements
    for (int i=0; i < 10; i++) {
        matrix[i] = malloc (sizeof(int) * 5);
    }

    int counter = 1;

    // fill the matrix
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = counter % 10;
            counter++;
        }
    }

    // print the matrix
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matrix[i][j]);
            counter++;
        }

        printf("\n");
    }

    return 0;
}
