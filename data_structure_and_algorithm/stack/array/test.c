#include <stdio.h>
#include "stack.h"

#define STACK_SIZE 5

static void stackApiTest(void)
{
    int i;
    STACK element;

    stackPush(0);
    stackPop(0);
    stackIsEmpty();
    stackLength();
    createStack(STACK_SIZE);
    createStack(STACK_SIZE);
    destoryStack();
    createStack(STACK_SIZE);
    for(i = 0; i < STACK_SIZE; i++) {
        printf("push %d\n", i);
        stackPush(i);
    }
    printf("length:%d\n", stackLength());
    stackPush(0); //stack is full

    for(i = 0; i < STACK_SIZE; i++) {
        stackPop(&element);
        printf("pop %d\n", element);
    }
    stackPop(&element); //stack is empty

    destoryStack();
    stackPush(0); //stack is not exsit;
}

int main(void)
{
    stackApiTest(); 

    return 0;
}
