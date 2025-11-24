#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    // Create and open a file
    fd = creat("sample.txt", 0777);
    if (fd < 0) {
        printf("File creation failed\n");
        return 1;
    }

    write(fd, "Hello UNIX System Calls!\n", 25);
    close(fd);

    // Re-open file for reading
    fd = open("sample.txt", O_RDONLY);
    if (fd < 0) {
        printf("File open failed\n");
        return 1;
    }

    int n = read(fd, buffer, sizeof(buffer));
    buffer[n] = '\0';

    printf("Content of file: \n%s\n", buffer);

    close(fd);
    return 0;
}
