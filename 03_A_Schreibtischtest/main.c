#include <stdio.h>

char* MethodB(int position, char *textPosition) {
    textPosition += position;

    return textPosition;
}

void MethodA(int position, char *point) {
    char* firstLetter = point;
    point = MethodB(position, point);
    char letter = *point;
    *point = *firstLetter;
    *firstLetter = letter;
}

int main() {
    int a = 4;
    char text[10] = "Hello HTL";
    char *start = text;

    printf("Show text     : %s\n", text);
    MethodA(a, start);
    printf("Show text now : %s\n", text);

    return 0;
}
