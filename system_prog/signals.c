#include <signal.h>
#include <stdio.h>
#include <unistd.h>

/*****************AMBIGUOUS********************/

// struct sigaction {
//     void* sa_handler;
//     int sa_flag;
// };

// void wakeup() {}

// unsigned int sleep(unsigned int timer) {
//     struct sigaction action;
//     action.sa_handler = wakeup;
//     action.sa_flag = 0;
//     sigemptyset()
// }

/***********************************************/
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