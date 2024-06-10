#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t process;
    process = fork();
    
    if (process == 0) {
        printf("Hello from the Child Process\n");
        _exit(0);
    }

    else {
        waitpid(0, NULL, 0);
        printf("Hello from the Parent Process\n");
//        waitpid(0, NULL, 0);
    }

    return 0;
}

