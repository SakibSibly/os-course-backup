#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    pid1 = fork();
    
    if (pid1 == 0) {    
        printf("Child1 has finished\n");
        _exit(0);
    } else {
        pid2 = fork();
        if (pid2 == 0) {
            printf("Child2 has finished\n");
            _exit(0);
        }
        // int *status = WIFEXITED(123);
        // waitpid(pid2, status, 0);
        waitpid(pid2, NULL, 0);
        printf("Parent finished\n");
    }

    return 0;
}