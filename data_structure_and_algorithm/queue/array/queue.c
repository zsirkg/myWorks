#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int initQueue(queueT *queue, int size)
{
    queue->contents = (queueElementT *)malloc(sizeof(queueElementT) * (size + 1)); //由于牺牲了一个位置，所以分配时多分配一个位置
    if(queue->contents == NULL) {
        perror("malloc");
        return -1;
    }

    queue->head = 0;
    queue->rear = 0;
    queue->size = size + 1;

    return 0;
}

int destroyQueue(queueT *queue)
{
    free(queue->contents);
    queue->contents = NULL;
} 

int queueIsEmpty(queueT *queue)
{
    if(queue->head == queue->rear) {
        return 1;
    }

    return 0;
}

int queueIsFull(queueT *queue)
{
    if(((queue->rear + 1) % queue->size) == queue->head) {
        return 1;
    }

    return 0;
}

int enqueue(queueT *queue, queueElementT element)
{
    if(queueIsFull(queue)) {
        printf("queue is full\n");
        return -1;
    }

    queue->contents[queue->rear % queue->size] = element;
    queue->rear = (queue->rear + 1) % queue->size;

    return 0;
}

int dequeue(queueT *queue, queueElementT *element)
{
    if(queueIsEmpty(queue)) {
        printf("queue is empty\n");
        return -1;
    }

    *element = queue->contents[queue->head % queue->size];
    queue->head = (queue->head + 1) % queue->size;

    return 0;
}

void queueTraverse(queueT *queue) 
{
    int i;

    if(queueIsEmpty(queue)) {
        printf("queue is empty\n");
        return;
    }

    i = queue->head;
    while(1) {
        printf("%d\n", queue->contents[i]);
        if((i + 1) % queue->size == queue->rear) {
            break;
        }
        i = (i + 1) % queue->size;
    }
}
