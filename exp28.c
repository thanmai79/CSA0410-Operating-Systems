#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    // Create / open a file
    fd = open("sample.txt", O_CREAT | O_RDWR, 0644);

    if (fd < 0) {
        printf("Error opening file\n");
        return 1;
    }

    // Write data to file
    write(fd, "Hello, Unix System Calls!\n", 27);

    // Move file pointer to beginning
    lseek(fd, 0, SEEK_SET);

    // Read data from file
    read(fd, buffer, 27);

    printf("Data read from file: %s\n", buffer);

    // Close file
    close(fd);

    return 0;
}
