#ifndef __LIST_H__
#define __LIST_H__

typedef struct node {
    int data;
    struct node *next;
}Node;

typedef struct list {
    Node *head;
    int length;
}List;

/* 创建并返回链表 */
List *createList(void);

/* 销毁链表 */
void destroyList(List *list);

/* 链表是否为空 */
int listIsEmpty(List *list);

/* 获取链表长度*/
int getListLength(List *list);

/* 获取链表positon位置节点的数据*/
int listGet(List *list, int position);

/* 在链表positon位置节点后插入一个节点*/
int listInsert(List *list, int data, int position);

/* 删除链表positon位置的节点*/
int listDelete(List *list, int position);

/* 遍历当前链表，打印数据*/
void listTraverse(List *list);

#endif
