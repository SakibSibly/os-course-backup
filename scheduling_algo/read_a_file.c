#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main() {
    int fd;
    ssize_t bytes_read;
    char buffer[BUFFER_SIZE];

    fd = open("test.txt", O_RDONLY);

    if (fd == -1) {
        perror("open");
        _exit(EXIT_FAILURE);
    }

    bytes_read = read(fd, buffer, BUFFER_SIZE);

    if (bytes_read == -1) {
        perror("read");
        close(fd);
        _exit(EXIT_FAILURE);
    }

    write(STDOUT_FILENO, buffer, bytes_read);

    close(fd);

    return 0;
}