#include <stdio.h>

// Deklaration der Funktion swap
void swap (int *i1, int *i2);

int main() {
    // Deklaration (Definition) + Initialisierung einer int Variablen
    // Name + Speicher + Wert <== Definition
    int i = 3;

    printf("Wert von i              = %d\n", i);
    printf("Adresse von i (dezimal) = %d\n", &i); // Adressoperator
    printf("Adresse von i (hex)     = 0x%x\n", &i); // Adressoperator
    printf("----------------------------------------\n");

    // Deklaration (Definition) eines int Zeigers
    // Name + Speicher + Zufallswert (besser int *p = NULL)
    int *p;
    printf("Wert von p              = %d\n", p);
    printf("Wert von p (hex)        = 0x%x\n", p);
    printf("Adresse von p (hex)     = 0x%x\n", &p); // Adressoperator
    printf("----------------------------------------\n");

    // Dem int Zeiger p wird die Adresse von i zugewiesen
    p = &i;
    printf("Wert von p (hex)        = 0x%x\n", p);
    printf("Adresse von p (hex)     = 0x%x\n", &p); // Adressoperator
    printf("----------------------------------------\n");


    *p = 12; // Die 12 "wird der Adresse auf die p zeigt" zugewiesen
    printf("Wert von i              = %d\n", i);
    printf("Inhalt des Zeigers p    = %d\n", *p); // Verweis-, Inhalts- oder Dereferenzierungsoperator
    printf("Adresse von i (hex)     = 0x%x\n", &i);
    printf("----------------------------------------\n");

    int x = 2;
    int y = 3;

    swap (&x, &y);

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}

void swap (int *i1, int *i2)
{
    int help;

    help = *i1;
    *i1 = *i2;
    *i2 = help;
}
