#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *source, *destination;
    char sourceFile[100], destFile[100];
    char ch;
    printf("Enter source file name: ");
    scanf("%s", sourceFile);
    
    printf("Enter destination file name: ");
    scanf("%s", destFile);
    source = fopen(sourceFile, "r");
    // If source not found, create it with sample content
    if (source == NULL) {
        printf("Source file not found, creating '%s' with sample data...\n", sourceFile);
        source = fopen(sourceFile, "w");
        fprintf(source, "This is a sample file for testing.\n");
        fclose(source);
        source = fopen(sourceFile, "r");
    }
    destination = fopen(destFile, "w");
    if (destination == NULL) {
        printf("Error opening destination file.\n");
        fclose(source);
        return 1;
    }
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }
    printf("File copied successfully!\n");
    fclose(source);
    fclose(destination);
    return 0;
}