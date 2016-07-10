#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int createStack(stackT *stack, int size)
{
    stack->contents = (stackElementT *)malloc(sizeof(stackElementT) * size);
    if(NULL == stack->contents) {
        perror("malloc");
        return -1;
    }
    stack->top = -1;
    stack->size = size;

    return 0;
}

void destoryStack(stackT *stack)
{
    free(stack->contents);
    stack->contents = NULL;
}

int stackIsEmpty(stackT *stack)
{
    if(-1 == stack->top) {
        return 1;
    } else {
        return 0;
    }
}

int stackPush(stackT *stack, stackElementT element)
{
    if(stack->top == stack->size - 1) {
        printf("stack is full.\n");
        return -1;
    }

    stack->top++;
    stack->contents[stack->top] = element;

    return 0;
}

int stackPop(stackT *stack, stackElementT *element)
{
    if(stackIsEmpty(stack)) {
        printf("stack is empty.\n");
        return -1;
    }

    *element = stack->contents[stack->top];
    stack->top--;

    return 0;
}
