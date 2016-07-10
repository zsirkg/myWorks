#ifndef __STACK_H__
#define __STACK_H__

typedef int stackElementT;
typedef struct stack {
    int top;
    int size;
    stackElementT *contents;
}stackT;

int createStack(stackT *stack, int size);
void destoryStack(stackT *stack);
int stackIsEmpty(stackT *stack);
int stackPush(stackT *stack, stackElementT element);
int stackPop(stackT *stack, stackElementT *element);

#endif
