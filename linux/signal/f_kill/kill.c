#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int signo)
{
    switch(signo) {
        case SIGUSR1:
            printf("get signal -- SIGUSR1\n");
            break;
        default:
            break;
    }

}

int main(int argc, char **argv)
{
    pid_t pid;
    struct sigaction act;

    act.sa_flags = 0;
    act.sa_handler = signal_handler;
    sigaction(SIGUSR1, &act, NULL);

    pid = getpid();

    printf("send SIGUSR1 to curent process\n");
    kill(pid, SIGUSR1);

    getchar();

    printf("thanks, bye!\n");

    return 0;
}
