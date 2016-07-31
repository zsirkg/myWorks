#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;
    int var = 0;

    pid = fork();

    if(pid == 0) {
        var++;
        printf("I'm child process, pid:[%d], var:%d\n", getpid(), var);
    } else if(pid > 0) {
        sleep(2); // 保证父进程在子进程后退出,便于观察var变量的独立性.
        printf("I'm parent process, pid:[%d], var:%d\n", getpid(), var);
    } else {
        printf("fork error\n");
    }

    return 0;
}
