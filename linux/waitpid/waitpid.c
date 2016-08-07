#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define CREATE_PROCESS_CNT 5

int main(void)
{
    pid_t pid;
    int i;
    int status;

    for(i = 0; i < CREATE_PROCESS_CNT; i++) {
        pid = fork();
        switch(pid) {
            case -1: /*error*/
                perror("fork");
                exit(1);
                break;
            case 0: /*child*/
                printf("I am child, exit status:%d pid:%d ppid:%d\n", i, getpid(), getppid());
                exit(i);
                break;
            default: /*parent*/
                break;
        
        }
    }

    sleep(1); //make sure all children had exited, before.
    i = 0;
    for( ;; ) {
        pid = waitpid(-1, &status, WNOHANG);
        if(pid == 0) { /* no child*/
            printf("no child to be waited\n");
            sleep(1);
        }

        if(pid > 0) {
            printf("collected child pid[%d] exit status is %d\n", pid, WEXITSTATUS(status));
            i++;
            if(i == CREATE_PROCESS_CNT) {
                printf("all children had exited\n");
                exit(0);
            }
        }

        if(pid == -1) {
            perror("waitpid");
            exit(1);
        }
    }

    return 0;
}
