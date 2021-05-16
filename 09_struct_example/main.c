#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_PERSONS 5

// struct without alias
struct Person {
   char firstName[15];
   char secondName[15];
   int age;
};

// struct with alias and keyword typedef
typedef struct Point {
    int x;
    int y;
} Point;

struct Point sumPoints(struct Point a, struct Point b);
void initializeConst();
void printArray(struct Person* persons, int i);

int main() {
    //first simple example
    Point a;
    a.x = 2;
    a.y = 5;
    Point b = {3 , 6};
    // with or without struct, that is here the question? or maybe not?
    struct Point c = sumPoints(a, b);
    printf("Point c = (%d/%d)\n\n", c.x, c.y);

    initializeConst();
    // 5 persons allocated
    struct Person *persons = malloc(NUM_OF_PERSONS * sizeof(struct Person));

    // why does this not work?
    //persons->secondName = "test";

    // are there an alternative to do this action?
    strcpy(persons->firstName, "Anton");
    // see the different way to point to the correct value
    strcpy((*persons).secondName, "Auer");
    (*persons).age=25;

    persons++;
    strcpy(persons->firstName, "Berta");
    strcpy(persons->secondName, "Barringer");
    persons->age = 22;

    // one step back
    persons--;

    // avoid this syntax if you already used pointer arithmetics!
    // what happens if you would not make the step back
    strcpy(persons[2].firstName, "Cäsar");
    strcpy(persons[2].secondName, "Clown");
    persons[2].age = 12;

    //persons--;
    printArray(persons, 4*sizeof(struct Person) );
}

struct Point sumPoints(struct Point a, struct Point b) {
    struct Point result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;

    return result;
}

void printArray(struct Person* persons, int i) {
    struct Person *iterator = persons;

    // is this smart? Be aware that this makes no sense!
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
    struct Person test = {"Franz", "Huber",52};

    struct Person array[] = {
            {"Max", "Mustermann", 24},
            {"Maria", "Musterfrau",     27},
            test
    };

    printArray(array, sizeof(array));
}
