#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int signo)
{
    switch(signo) {
        case SIGINT:
            printf("handle SIGINT by user\n");
            break;
        default:
            break;
    }

}

int main(int argc, char **argv)
{
    struct sigaction act;

    printf("ctr-c will be handled by user, enter to continue..\n");
    act.sa_flags = 0;
    act.sa_handler = signal_handler;
    sigaction(SIGINT, &act, NULL);
    getchar();

    printf("ctr-c will be ignore, enter to continue..\n");
    act.sa_flags = 0;
    act.sa_handler = SIG_IGN;
    sigaction(SIGINT, &act, NULL);
    getchar();

    printf("ctr-c will handle by default, enter to continue..\n");
    act.sa_flags = 0;
    act.sa_handler = SIG_DFL;
    signal(SIGINT, SIG_DFL);
    getchar();

    printf("thanks, bye!\n");

    return 0;
}
