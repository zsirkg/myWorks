#ifndef __STACK_H__
#define __STACK_H__

/**
 * 栈元素为int
 * 也可为其他类型或为结构体
 * 以书籍结构体为例:
typedef struct {
    char *book_name[32];
    char *book_author[32];
}STACK;
 *
 **/
typedef int STACK; 

int createStack(int size);      /*创建大小为size的栈*/
void destoryStack(void);        /*销毁栈*/
int stackIsEmpty(void);         /*栈是否为空*/
int stackLength(void);          /*栈中元素个数*/
int stackPush(STACK element);   /*向栈中添加元素*/
int stackPop(STACK *element);   /*获取顶元素, 并出栈*/

#endif
