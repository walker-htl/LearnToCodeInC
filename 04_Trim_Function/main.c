#include <stdio.h>
#include <stdlib.h>

int lettercount(char* string){
    int i=0;
    while (*string!='\0'){
        i++;
        string++;
    }
    return i;
}

char* reversestring(char* string) {
    int length = lettercount(string);
    char* revstring = calloc(length+1,sizeof (char));
    string= string + (length - 1);
    int i=0;
    while (i<length){
        *revstring= *string;
        revstring++;
        string--;
        i++;
    }
    *revstring='\0';
    revstring=revstring-length;
    return revstring;
}
char* trim(char *string){
    while (*string==' '){
        string++;
    }
    string=reversestring(string);
    while (*string==' '){
        string++;
    }

    string=reversestring(string);
    return string;
}


int main() {
    char t1[] = "No spaces";
    char t2[] = " One front space";
    char t3[] = "   Front spaces";
    char t4[] = "One back space ";
    char t5[] = "Back spaces   ";
    char t6[] = "  Front and back spaces   ";
    printf("[%s] -> [%s]\n", t1, trim(t1));
    printf("[%s] -> [%s]\n", t2, trim(t2));
    printf("[%s] -> [%s]\n", t3, trim(t3));
    printf("[%s] -> [%s]\n", t4, trim(t4));
    printf("[%s] -> [%s]\n", t5, trim(t5));
    printf("[%s] -> [%s]\n", t6, trim(t6));
    return 0;
}
