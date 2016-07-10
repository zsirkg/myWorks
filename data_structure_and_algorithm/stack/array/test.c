#include <stdio.h>
#include "stack.h"

#define STACK_SIZE 5

static void stackApiTest(void)
{
    int i;
    stackT stack;
    stackElementT element;

    createStack(&stack, STACK_SIZE);
    for(i = 0; i < STACK_SIZE; i++) {
        stackPush(&stack, i);
        printf("push %d\n", i);
    }

    for(i = 0; i < STACK_SIZE; i++) {
        stackPop(&stack, &element);
        printf("pop %d\n", element);
    }

    destoryStack(&stack);
}

int main(void)
{
    int cnt = 1;

    while(cnt--)
        stackApiTest(); 

    return 0;
}
