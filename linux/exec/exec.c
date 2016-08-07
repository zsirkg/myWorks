#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;

    while(1) {
        
        pid = fork();
        switch(pid) {
            case -1:
                perror("fork");
                exit(1);
                break;
            case 0:
                printf("execute \"ls -l\"\n");
                execl("/bin/ls", "ls", "-l", NULL);
                perror("execl");
                exit(1);
                break;
            default:
                /*按下q键退出，其他键继续*/
                if(getchar() == 'q') {
                    exit(1);
                }
                break;
        }
    }

    return 0;
}
