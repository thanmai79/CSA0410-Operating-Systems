#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    // Create and write to file
    fd = open("sample.txt", O_CREAT | O_WRONLY, 0644);
    write(fd, "Hello UNIX System Calls!\n", 26);
    close(fd);

    // Open file for reading
    fd = open("sample.txt", O_RDONLY);
    read(fd, buffer, sizeof(buffer));
    printf("File Content:\n%s\n", buffer);

    // Move file pointer
    lseek(fd, 0, SEEK_SET);

    close(fd);
    return 0;
}
