#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define QUEUE_SIZE 5

int main(int argc, char *argv[])
{
    queueT queue;
    int element;
    int i;

    initQueue(&queue, QUEUE_SIZE);

    if(1 == queueIsEmpty(&queue)) {
        printf("queue is empty.\n");
    }

    enqueue(&queue, 0);
    if(1 == queueIsEmpty(&queue)) {
        printf("queue is empty.\n");
    }

    dequeue(&queue, &element);
    printf("get element:%d\n", element);
    if(1 == queueIsEmpty(&queue)) {
        printf("queue is empty.\n");
    }

    for(i = 0; i < QUEUE_SIZE; i++) {
        enqueue(&queue, i);
    }
    enqueue(&queue, i);
    if(1 == queueIsFull(&queue)) {
        printf("queue is full.\n");
    }
    queueTraverse(&queue);

    for(i = 0; i < QUEUE_SIZE; i++) {
        dequeue(&queue, &element);
        printf("get element:%d\n", element);
    }
    dequeue(&queue, &element);
    queueTraverse(&queue);

    destroyQueue(&queue);

    return 0;
}
