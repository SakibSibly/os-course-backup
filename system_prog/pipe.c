#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

char arg[10][150], ar[1000];

int main(int argc, char* argv[])
 {
    int i=0, j=0, k=0;
    int pipe_fd[2];
    pid_t ls_pid, grep_pid;

   gets(ar);
   pipe(pipe_fd);

    for(i=0; ar[i]; i++)
    {
        if(ar[i] == ' ')
        {
            arg[k++][j] = NULL;
            j = 0;
            continue;
        }
        arg[k][j++] = ar[i];
    }

    arg[k++][j] = NULL;
    ls_pid = fork();

    if (ls_pid == 0)
    {
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(pipe_fd[0]);

        execlp(arg[0], arg[0], arg[1], NULL);
        perror("exec");

        return 1;
    }
    grep_pid = fork();

    if (grep_pid == 0)
    {

      dup2(pipe_fd[0], STDIN_FILENO);
      close(pipe_fd[1]);

      execlp(arg[3], arg[3], arg[4], NULL);
      perror("exec");

      return 1;

    }

    close(pipe_fd[0]);
    close(pipe_fd[1]);
    waitpid(ls_pid);
    waitpid(grep_pid);
    return 0;
}

