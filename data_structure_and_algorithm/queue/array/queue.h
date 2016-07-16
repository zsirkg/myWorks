#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef int queueElementT;

typedef struct {
    int head;
    int rear;
    int size;
    queueElementT *contents;
}queueT;

int initQueue(queueT *queue, int size);                 /* 初始化队列，size为队列长度 */
int destroyQueue(queueT *queue);                        /* 销毁队列 */
int queueIsEmpty(queueT *queue);                        /* 队列是否为空 */
int queueIsFull(queueT *queue);                         /* 队列是否为满 */
int enqueue(queueT *queue, queueElementT element);      /* 入队 */
int dequeue(queueT *queue, queueElementT *element);     /* 出队 */
void queueTraverse(queueT *queue);                      /* 遍历打印队列中元素 */

#endif
