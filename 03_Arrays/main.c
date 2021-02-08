#include <stdio.h>

#define MAX_VALUES 100

void print_numbers(int numbers[]){
    int i = 0;

    printf("Gespeicherte Zahlen: \n");
    while(i < MAX_VALUES && numbers[i] >= 0){
        printf("%d\n", numbers[i]);
        i++;
    }
}

float calc_average(int numbers[]){
    int i = 0;
    int sum = 0;

    while(i < MAX_VALUES && numbers[i] >= 0){
        sum += numbers[i];
        i++;
    }
    return (float)sum/i;
}

int min_value(int numbers[]){
    int i = 1;
    int min = numbers[0];

    while(i < MAX_VALUES && numbers[i] >= 0){
        if (numbers[i] < min)
            min = numbers[i];
        i++;
    }
    return min;
}

int main() {
    int numbers[MAX_VALUES];
    int input = -1;
    int i = 0;

    printf ("Geben Sie beliebig viele Zahlen ein, -1 beendet die Ausgabe!\n");

    do{
        printf("? ");
        scanf ("%d", &input);

        numbers[i] = input;
        i++;

    }while (i < MAX_VALUES && input >= 0);

    print_numbers(numbers);

    printf("Mittelwert: %.2f\n", calc_average(numbers));

    return 0;
}