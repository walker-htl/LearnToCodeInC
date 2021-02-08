#include <stdio.h>
#include <math.h>

void printChars(char c, int amount){
    for (int i = 0; i < amount; ++i) {
        printf("%c", c);
    }
    printf("\n");
}

float calculateBMI(float weight, float height){
    return (weight/powf(height, 2));
}

int main() {
    float weight = 0.0f;
    float height = 0.0f;
    float bmi = 0.0f;

    printf("B M I - C A L C U L A T O R\n");
    printChars('=', 27);

    printf("\nYour weight (in kg): ");
    scanf("%f", &weight);

    printf("\nYour height (in m): ");
    scanf("%f", &height);

    bmi = calculateBMI(weight, height);
    printf("Your BMI is %.2f\n", bmi);


    return 0;
}


// discord test...