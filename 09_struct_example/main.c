#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_PERSONS 5

struct Person {
   char firstName[15];
   char secondName[15];
   int age;
};

void initializeConst(void);
void printArray(struct Person* persons, int i);

int main() {
    initializeConst();
    // 5 persons allocated
    struct Person *persons = malloc(NUM_OF_PERSONS * sizeof(struct Person));

    strcpy(persons->firstName, "A");
    strcpy(persons->secondName, "B");
    persons->age=25;

    //persons++;
    strcpy(persons[1].firstName, "B");
    strcpy(persons[1].secondName, "bb");
    persons[1].age = 12;

    printArray(persons, 2*sizeof(struct Person) );
}

void printArray(struct Person* persons, int i) {
    struct Person *iterator = persons;
    int size = i / sizeof persons[0];

    for (int i = 0; i < size; i++) {
        printf("fN: %s, lN:%s, age:%d\n", iterator->firstName, iterator->secondName, (*iterator).age);
        //printf("fN: %s, lN:%s, age:%d\n", (*iterator).firstName, iterator->secondName, iterator->age);
        iterator++;
    }
    printf("\n");

    // better
    for (int i = 0; i < size; i++) {
        printf("fN: %s, lN:%s, age:%d\n", persons[i].firstName, persons[i].secondName, persons[i].age);
    }
    printf("------- End ---------\n");
}

void initializeConst(void) {
    struct Person array[] = {
            {"Max\0", "Mustermann\0", 24},
            {"Maria\0", "Musterfrau\0",     27},
    };

    printArray(array, sizeof(array));
}
