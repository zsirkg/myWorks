#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *createList(void)
{
    List *list;
    list = (List *)malloc(sizeof(List));
    if(NULL == list) {
        return NULL;
    }
    list->head = (Node *)malloc(sizeof(Node));
    if(NULL == list->head) {
        free(list);
        return NULL;
    }

    list->head->data = 0;
    list->head->next = NULL;
    list->length = 0;
    return list;
}

void destroyList(List *list)
{
    Node *cur, *tmp;

    cur = list->head;
    while(cur != NULL) {
        tmp = cur->next;
        free(cur);
        cur = tmp;
    }

    free(list);
    list = NULL;

}

int listIsEmpty(List *list)
{
    if(list->length == 0) {
        return 1;
    }

    return 0;
}
/**
 * 插入数据到postion位置的后边
 * param list 链表指针
 * param data 插入的数据
 * param postion 插入数据的位置, 0表示在在头节点后插入
 */
int listInsert(List *list, int data, int position)
{
    Node *cur;
    Node *newNode;
    int i = 0;

    if(list->head == NULL) {
        printf("list have not initialized\n");
        return -1;
    }
    if(position < 0 || position > list->length) {
        printf("insert node position:%d is invalid\n", position);
        return -1;
    }

    newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL) {
        return -1;
    }
    newNode->data = data;

    cur = list->head;
    for(i = 0; i < position; i++) { //找到position位置的节点
        cur = cur->next;
    }

    newNode->next = cur->next;
    cur->next = newNode;
    list->length++;

    return 0;
}

int listDelete(List *list, int position)
{
    int i;
    Node *cur, *del;

    if(list->head == NULL) {
        printf("list have not initialized\n");
        return -1;
    }
    if(list->length == 0) {
        printf("list is Empty\n");
        return -1;
    }
    if(position < 1 || position > list->length) { //position不能为0，因为不能删除头节点
        printf("delete node position:%d is invalid\n", position);
        return -1;
    }

    cur = list->head;
    for(i = 0; i < position - 1; i++) { //找到要删除节点的前一个节点
        cur = cur->next;
    }

    del = cur->next;
    cur->next = del->next;

    free(del);
    del = NULL;
    list->length--;

    return 0;
}

int listGet(List *list, int position)
{
    int i;
    Node *cur;

    if(list->head == NULL) {
        printf("list have not initialized\n");
        return -1;
    }
    if(list->length == 0) {
        printf("list is Empty\n");
        return -1;
    }
    if(position < 1 || position > list->length) { //position不能为0，头节点没有数据
        printf("insert node position:%d is invalid\n", position);
        return -1;
    }

    cur = list->head;
    for(i = 0; i < position; i++) { //找到position位置的节点
        cur = cur->next;
    }

    return cur->data;
}

void listTraverse(List *list)
{
    Node *cur;

    if(list->head == NULL || list->head->next == NULL) {
        return;
    }

    for(cur = list->head->next; cur != NULL; cur = cur->next) {
        printf("[%s] %d\n", __FUNCTION__, cur->data);
    }
}
