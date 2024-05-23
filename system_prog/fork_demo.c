#include <stdio.h>
#include <unistd.h>     // Only available in linux
#include <sys/types.h>  //

int main() {
    pid_t child_pid;

    // child_pid = vfork();
    child_pid = fork();

    if (child_pid == 0) {
        printf("I'm in the child process\n");
        printf("Child ID: %d and Parent ID: %d and GROUP ID: %d\n", getpid(), getppid(), getpgrp());
    }
    else if (child_pid > 0) {
        printf("I'm in the parent process\n");
        printf("Parent ID: %d Grant parent ID: %d and GROUP ID: %d\n", getpid(), getppid(), getpgrp());
    }
    else {
        printf("fork failed\n");
    }

    return 0;
}