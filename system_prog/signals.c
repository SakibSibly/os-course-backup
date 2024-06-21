#include <signal.h>
#include <stdio.h>
    #include <unistd.h>

void catch_sig(int sig_num) {
    signal(sig_num, catch_sig);
    printf("catch_sig: %d\n", sig_num);
}

int main() {
    signal(SIGTERM, catch_sig);
    signal(SIGINT, SIG_IGN);
    signal(SIGSEGV, SIG_DFL);
    pause();
}