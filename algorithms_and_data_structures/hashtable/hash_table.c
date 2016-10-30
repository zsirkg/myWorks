#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

static Node_T *createNode(Info_T *info);
static BOOL nodeLookup(Node_T *head, Info_T *targetInfo);

static BOOL hasInit = FALSE;
static int hash(Info_T *info)
{
    int index;

    index = info->key % MAX_HASH_TABLE_LEN;

    return index;
}

// must same as hash();
static int hashByKey(int key)
{
    int index;

    index = key % MAX_HASH_TABLE_LEN;

    return index;
}

BOOL hashTableInit()
{
    
    memset(hashTable, 0, sizeof(Node_T) * MAX_HASH_TABLE_LEN);
    hasInit = TRUE;

    return TRUE;
}

BOOL hashTableInsert(Info_T *info)
{
    int i;

    if(NULL == info) {
        print_d("invalid information!\n");
        return FALSE;
    }

    i = hash(info);
    if(NULL == hashTable[i]) {
        hashTable[i] = (Node_T *)malloc(sizeof(Node_T));
        if(NULL == hashTable[i]) {
            return FALSE;
        }
        print_d("hashTable[%d]: add a head node, value is %d\n", i, info->value);
        hashTable[i]->info.key = info->key;
        hashTable[i]->info.value = info->value;
    } else {
        Node_T *cur;
        Node_T *last;

        cur = hashTable[i];
        while(cur != NULL) {
            if(cur->info.key == info->key) {
                print_d("update information\n");
                cur->info.value = info->value;
                return TRUE;
            }
            last = cur;
            cur = cur->next;
        }

        print_d("hashTable[%d]: add a head node, value is %d\n", i, info->value);
        cur = (Node_T *)malloc(sizeof(Node_T));
        cur->info.key = info->key;
        cur->info.value = info->value;
        last->next = cur;
    }

    return TRUE;
}

BOOL hashTableLookupByKey(int key)
{
    int i;

    i = hashByKey(key);
    if(NULL == hashTable[i]) {
        return FALSE;
    } else {
        Node_T *cur;

        cur = hashTable[i];
        while(cur != NULL) {
            if(cur->info.key == key) {
                print_d("find key %d, the value is %d\n", key, cur->info.value);
                return TRUE;
            }
            cur = cur->next;
        }
    }

    return FALSE;
}

BOOL hashTableLookup(Info_T *info)
{
    int i;

    if(NULL == info) {
        print_d("invalid information!\n");
        return FALSE;
    }

    i = hash(info);
    if(NULL == hashTable[i]) {
        return FALSE;
    } else {
        Node_T *cur;

        cur = hashTable[i];
        while(cur != NULL) {
            if(cur->info.key == info->key) {
                print_d("find key, the value is %d\n", info->value);
                cur->info.value = info->value;
                return TRUE;
            }
            cur = cur->next;
        }
    }

    return FALSE;
}

void hashTableShow()
{
    int i;
    Node_T *cur;

    if(hasInit == FALSE) {
        return;
    }

    for(i = 0; i < MAX_HASH_TABLE_LEN; i++) {
        if(hashTable[i] != NULL) {
            printf("[%d] ", i);
            cur = hashTable[i];
            while(cur != NULL) {
                printf("-->%d", cur->info.value);
                cur = cur->next;
            }
            hashTable[i] = NULL;
            printf("\n");
        }
    }
}

void hashTableDeinit()
{
    // free resource, and set element to NULL
    int i;
    Node_T *cur;
    Node_T *tmp;

    if(hasInit == FALSE) {
        return;
    }

    for(i = 0; i < MAX_HASH_TABLE_LEN; i++) {
        if(hashTable[i] != NULL) {
            cur = hashTable[i];
            while(cur != NULL) {
                tmp = cur->next;
                free(cur);
                cur = tmp;
            }
            hashTable[i] = NULL;
        }
    }

    hasInit = FALSE;
}
