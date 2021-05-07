#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int loadFileIntoMemory(const char *filename, char **result)
{
    // if you have got issues finding your file
    // check your Working directory in "Edit Configurations..."
    char buf[1024]; // hack, but fine for this
    printf("--> %s\n", getcwd(buf, 1024));

    int size;
    // modes: r -> read, b -> binary (necessary for windows!)
    FILE *f = fopen(filename, "rb");

    if (f == NULL)
    {
        printf("something went wrong with read()! %s\n", strerror(errno));
        *result = NULL;
        return -1; // -1 means file opening fail
    }

    // Get the number of bytes
    fseek(f, 0, SEEK_END);
    size = ftell(f);

    // reset the file position indicator to the beginning of the file
    fseek(f, 0, SEEK_SET);

    *result = (char *)malloc(size+1);

    // reads the file
    if (size != fread(*result, sizeof(char), size, f))
    {
        free(*result);
        return -2; // -2 means file reading fail
    }

    fclose(f);
    (*result)[size] = '\0';

    return size;
}

int main() {
    char *content;
    int size;
    char *fileName = "test.txt";
    size = loadFileIntoMemory(fileName, &content);

    if (size < 0)
    {
        puts("Error loading file");
        return 1;
    }

    printf("%s\n", content);

    return 0;
}

int getNumberOfLines(char *content) {
    char* ch = content;
    int lines = 0;

    while (*ch != '\0') {
        // Check new line
        if (*ch == '\n' || *ch == '\0') {
            lines++;
        }
        ch++;
    }

    return lines;
}