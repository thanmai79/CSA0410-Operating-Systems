#include <stdio.h>
#include <stdlib.h>
#include <direct.h>   // for _mkdir on Windows

int main() {
    char mainDirectory[] = "C:/Users/itssk/OneDrive/Desktop";
    char subDirectory[]  = "os";
    char fileName[]      = "example.txt";

    char mainDirPath[200];
    char filePath[300];

    // Create full directory path
    snprintf(mainDirPath, sizeof(mainDirPath), "%s/%s", mainDirectory, subDirectory);

    // Create subdirectory (Windows uses _mkdir)
    _mkdir(mainDirPath);   // If folder exists, it's OK

    // Create final file path
    snprintf(filePath, sizeof(filePath), "%s/%s", mainDirPath, fileName);

    // Create file
    FILE *file = fopen(filePath, "w");

    if (file == NULL) {
        printf("Error creating file.\n");
        return 1;
    }

    fprintf(file, "This is an example file content.");
    fclose(file);

    printf("File created successfully at:\n%s\n", filePath);

    return 0;
}
