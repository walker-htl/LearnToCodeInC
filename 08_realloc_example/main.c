#include <stdio.h>
#include <stdlib.h>

int main() {
    int* field = malloc(1*sizeof(int));
    printf ("Geben Sie beliebig viele Zahlen ein, -1 beendet die Ausgabe!\n");
    int index = 0;

    do{
        printf("? ");
        // Wir übergeben hier direkt den Pointer, daher kein Adressoperator
        scanf ("%d", (field + index));

        if (*(field + index) < 0)
        {
            break;
        }

        index++;
        // dynamische Erweiterung des Speichers
        field = realloc(field, index*sizeof (int));
    } while (1);

    for (int i = 0; i < index; i++) {
        printf("%d\n", *(field + i)); //*field[i] ...
    }

    return 0;
}
