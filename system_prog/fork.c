#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;

    printf("PID: %d, parent: %d\n", getpid(), getppid());
    printf("Group ID for main: %d\n", getgid());


    switch (child_pid = fork()) {
        case (pid_t)-1:
        perror("fork failed\n");
        printf("Group ID for failed fork: %d\n", getgid());
        break;

        case (pid_t)0:
        printf("child created: PID: %d, parent: %d\n", getpid(), getppid());
        printf("Group ID for child: %d\n", getgid());
        waitpid(child_pid, NULL, 0);
        _exit(0);

        default:
        printf("parent id: %d\n",getpid());
        printf("Group ID for parent: %d\n", getgid());

    }

    return 0;
}
