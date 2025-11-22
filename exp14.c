#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void copy() {
    const char *sourcefile = "C:/Users/itssk/OneDrive/Desktop/sasi.txt";
    const char *destination_file = "C:/Users/itssk/OneDrive/Desktop/sk.txt";

    int source_fd = open(sourcefile, O_RDONLY);
    if (source_fd < 0) {
        printf("Unable to open source file!\n");
        return;
    }

    int dest_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (dest_fd < 0) {
        printf("Unable to create destination file!\n");
        close(source_fd);
        return;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    while ((bytesRead = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        write(dest_fd, buffer, bytesRead);
    }

    close(source_fd);
    close(dest_fd);

    printf("File copied successfully.\n");
}

void create() {
    FILE *fp;
    fp = fopen("C:/Users/itssk/OneDrive/Desktop/sasi.txt", "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return;
    }
    printf("File created successfully.\n");
    fclose(fp);
}

int main() {
    int n;

    printf("1. Create  \t2. Copy  \t3. Delete\nEnter your choice: ");
    scanf("%d", &n);

    switch (n) {
        case 1:
            create();
            break;

        case 2:
            copy();
            break;

        case 3:
            remove("C:/Users/itssk/OneDrive/Desktop/sasi.txt");
            printf("Deleted successfully.\n");
            break;

        default:
            printf("Invalid option.\n");
    }

    return 0;
}
