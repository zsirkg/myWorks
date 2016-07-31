#ifndef __STACK_H__
#define __STACK_H__

typedef int stackElementT;
typedef struct stack {
    int top;
    int size;
    stackElementT *contents;
}stackT;

int initStack(stackT *stack, int size);                 /* 初始化栈，大小为size*/
void destoryStack(stackT *stack);                       /* 销毁栈 */
int stackIsEmpty(stackT *stack);                        /* 栈是否为空 */
int stackPush(stackT *stack, stackElementT element);    /* 入栈 */
int stackPop(stackT *stack, stackElementT *element);    /* 出栈 */

#endif
