#include <stdio.h>
#include <sys/time.h>
#include "hash_table.h"

#define TEST_SIZE 1030000

void printTime()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    printf("%lu\n", tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int main()
{
    Info_T info = {1, 10};
    int i;

    hashTableInit();
    printTime();
    for(i = 0; i < TEST_SIZE; i++) {
        hashTableInsert(&info);
        ++(info.key);
        info.value += 2;
    }
    printTime();
    hashTableLookupByKey(1);
    printTime();
    //hashTableShow();
    hashTableDeinit();


    return 0;
}
