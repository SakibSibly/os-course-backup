#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>


int main() {
    pid_t pid1;
    for (int i = 1; i <= 10; ++i) {
        pid1 = fork();
        if (pid1 == 0) {
            printf("Hello World from child %d and the process %d\n", getpid(), getppid());
            _exit(0);
        }
    }


    return 0;
}