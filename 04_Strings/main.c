#include <stdio.h>

#define MAX_LEN 100

// str[] -> call by reference
void swap_chars(char str[100], char oldChar, char newChar) {
    int i = 0;

    while (i<MAX_LEN && str[i]!='\0'){
        if (str[i] == oldChar)
            str[i] = newChar;
        i++;
    }
}

// call by value: wert der übergeben wird ist eine KOPIE
void changeA(int a){
    a = 17;
}

int main() {
    char str[MAX_LEN] = "Hello World!\n";

    printf("%s", str);

    swap_chars(str, 'l', 'x');

    printf("%s", str);

    int a = 0;

    changeA(a);
    printf("%d", a);

    return 0;
}

