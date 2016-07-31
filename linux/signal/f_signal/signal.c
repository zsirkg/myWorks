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
    printf("ctr-c will be handled by user, enter to continue..\n");
    signal(SIGINT, signal_handler);
    getchar();

    printf("ctr-c will be ignore, enter to continue..\n");
    signal(SIGINT, SIG_IGN);
    getchar();

    printf("ctr-c will handle by default, enter to continue..\n");
    signal(SIGINT, SIG_DFL);
    getchar();

    printf("thanks, bye!\n");

    return 0;
}
