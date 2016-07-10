#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

static int stackTop = -1;
static int stackSize = -1;
static int *stack = NULL;

int createStack(int size)
{
    if(stack) {
        printf("stack had created!\n");
        return -1;
    }

    stackTop = -1;
    stackSize = size;
    stack = (STACK *)malloc(sizeof(STACK) * size);
    if(NULL == stack) {
        perror("malloc");
        return -1;
    }

    return 0;
}

void destoryStack(void)
{
    free(stack);
    stack = NULL;
}

int stackIsEmpty(void)
{
    if(NULL == stack) {
        printf("stack is not exist.\n");
        return -1;
    }

    if(-1 == stackTop) {
        return 1;
    } else {
        return 0;
    }
}

int stackLength(void)
{
    if(NULL == stack) {
        printf("stack is not exist.\n");
        return -1;
    }

    return stackTop + 1; /* stack top is begin from zero.*/
}


int stackPush(STACK element)
{
    if(NULL == stack) {
        printf("stack is not exist.\n");
        return -1;
    }

    if(stackTop == stackSize - 1) {
        printf("stack is full.\n");
        return -1;
    }

    memcpy(&stack[stackTop], &element, sizeof(STACK));
    stackTop++;

    return 0;
}

int stackPop(STACK *element)
{
    if(NULL == stack) {
        printf("stack is not exist.\n");
        return -1;
    }

    if(NULL == element) {
        printf("element is NULL.\n");
        return -1;
    }

    if(stackIsEmpty()) {
        printf("stack is empty.\n");
        return -1;
    }

    stackTop--;
    memcpy(element, &stack[stackTop], sizeof(STACK));

    return 0;
}
