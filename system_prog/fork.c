#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t child_pid;

    printf("PID: %d, parent: %d\n", getpid(), getppid());

    switch (child_pid = fork()) {
        case (pid_t)-1:
        perror("fork failed\n");
        break;

        case (pid_t)0:
        printf("child created: PID: %d, parent: %d\n", getpid(), getppid());
        _exit(0);

        default:
        printf("parent id: %d\n",getpid());
    }

    return 0;
}
