#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;

    // Opening file for writing
    file = fopen("example.txt", "w");
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        return 1;
    }

    // Writing data to the file
    fprintf(file, "Hello, World!\n");
    fprintf(file, "This is a C file management example.\n");

    fclose(file);

    // Opening file for reading
    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening the file for reading.\n");
        return 1;
    }

    char buffer[100];

    // Reading content line-by-line
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);

    return 0;
}
