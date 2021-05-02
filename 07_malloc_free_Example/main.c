#include <stdio.h>
#include <stdlib.h>

int *createArray(unsigned int n);

int main() {
    int *arr = NULL;
    unsigned int val=0, i=0;

    // 8 GB Linux Rechner:
    // 6 GB konnten allokiert werden 1.500.000.000 Elemente
    // 8 GB konnten nicht allokiert werden 2.000.000.000 Elemente
    printf ("Wie viele int-Elemente benötigen Sie? ");
    // Tastaturpuffer leeren, da als nächstes sonst ein "Enter" eingelesen würde
    //fflush(stdout); // ist nicht notwendig, wird aber oft gelehrt!
    scanf("%u", &val);
    arr = createArray(val);

    if (arr==NULL) {
        printf ("nicht genügend speicher");
        return -1;
    }

    printf ("Ausgabe der Elemente\n");

    for (i=0;i<val;i++) {
        printf ("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);
    arr=NULL;

    return 0;
}

// reserviert einen Speicherbereich für n-INT Werte
// und gibt einen Zeiger darauf zurück
int *createArray(unsigned int n) {
    int *iptr = NULL;
    unsigned int i = 0;
    iptr = malloc (n*(sizeof(int)));

    if (iptr!=NULL) {
        for (i = 0; i < n; i++) {
            iptr[i] = i; // *(iptr+i) = ...;
        }
    }

    return iptr;
}
