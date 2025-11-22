#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {
    int fd;

    // Open file (read-only). If not exists, create it with 0644 permission.
    fd = open("foo.txt", O_RDONLY | O_CREAT, 0644);

    printf("fd = %d\n", fd);

    if (fd == -1) {
        printf("Error Number: %d\n", errno);
        perror("Program Error");
        return 1;
    }

    close(fd);
    return 0;
}
