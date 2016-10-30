#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

#define MAX_HASH_TABLE_LEN 1024
#define BOOL int
#define TRUE 1
#define FALSE 0

#if 1
#define print_d
#else
#define print_d printf
#endif

typedef struct Info {
    int key;
    int value;
} Info_T;

typedef struct Node {
    struct Node *next;
    Info_T info;
} Node_T;

static Node_T *hashTable[MAX_HASH_TABLE_LEN];

BOOL hashTableInit();
BOOL hashTableInsert(Info_T *info);
BOOL hashTableLookup(Info_T *info);
BOOL hashTableLookupByKey(int key);
void hashTableShow();
void hashTableDeinit();

#endif
