#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void listTest(void)
{
    List *list;
    int i;

    list = createList();

    printf("delete when list is empty\n");
    listDelete(list, 0);

    printf("insert 0\n");
    listInsert(list, 0, 0);
    listTraverse(list);

    printf("delect position:0\n");
    listDelete(list, 0);
    listTraverse(list);
    
    printf("insert 5 element to list\n");
    for(i = 0; i < 5; i++) {
        listInsert(list, 5 - i, 0);
    }
    listTraverse(list);

    printf("insert 55 to position 3\n");
    listInsert(list, 55, 3);
    listTraverse(list);

    printf("delete first tree element\n");
    for(i = 0; i < 3; i++) {
        listDelete(list, 0);
    }
    listTraverse(list);

    printf("delete position 1\n");
    listDelete(list, 1);
    listTraverse(list);

    printf("get position 3\n");
    printf("postion 3:%d\n", listGet(list, 3));

    destroyList(list);
}

int main(void)
{
    listTest();

    return 0;
}
