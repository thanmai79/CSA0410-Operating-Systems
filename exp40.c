#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    // Create/Open file
    fd = open("sample.txt", O_CREAT | O_RDWR, 0644);
    if (fd < 0) {
        printf("Error opening file\n");
        return 1;
    }

    // Write to file
    write(fd, "Hello UNIX System Calls!\n", 26);

    // Move file pointer to beginning
    lseek(fd, 0, SEEK_SET);

    // Read from file
    int n = read(fd, buffer, sizeof(buffer));
    buffer[n] = '\0';

    printf("Data in file: %s\n", buffer);

    // Close file
    close(fd);

    return 0;
}
