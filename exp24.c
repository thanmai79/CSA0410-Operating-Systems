#include <stdio.h>
#include <fcntl.h>      // open, O_CREAT, O_RDWR
#include <unistd.h>     // read, write, close, lseek
#include <string.h>     // strlen

int main() {
    int fd;
    char buffer[100];

    // 1. Create / Open file
    fd = open("demo.txt", O_CREAT | O_RDWR, 0644);
    if (fd < 0) {
        perror("File open failed");
        return 1;
    }

    // 2. Write to file
    char *text = "Hello, UNIX System Calls!\n";
    write(fd, text, strlen(text));

    // 3. Move file pointer back to the beginning
    lseek(fd, 0, SEEK_SET);

    // 4. Read from file
    int bytesRead = read(fd, buffer, sizeof(buffer));
    buffer[bytesRead] = '\0';

    // 5. Display read content
    printf("Content read from file:\n%s", buffer);

    // 6. Close file
    close(fd);

    return 0;
}
