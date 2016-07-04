#include <stdio.h>

#define str(s) #s
#define cat(a, b) a##b

int main(int argc, char **argv)
{
    int i1 = 1;

    printf("%s\n", str(ssss)); //将ssss转换成字符串并输出。
    printf("%d\n", cat(i, 1)); //将i和1连接起来，因此出去i1的值。

    return 0;
}

