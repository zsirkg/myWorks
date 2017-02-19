#include <iostream>
#include <stdlib.h>
#include "list.h"
using namespace std;

static const int length = 11;
static const int lastKth = 5;
int main()
{
    List list;

    for(int i = length; i > 0; i--) {
        Node *node = new Node(i);
        list.insertNode(node);
    }
    list.print();

    if(list.hasCircle()) {
        cout << "List has circle" << endl;
        Node *first = list.getFirstNodeInCircle();
        if(first) {
            cout << "first circle node is " << first->data_ << endl;
        }
        exit(0);
    }
    cout << "List does not have circle" << endl;

    list.printReverse();
    list.printReverseRecursion();

    Node *nodeRK;
    nodeRK = list.getRK(lastKth);
    if(nodeRK != NULL) {
        cout << "The last " << lastKth << "th node from bottom is " << nodeRK->data_ << endl;
    }

    Node *nodeMid;
    nodeMid = list.getMiddle();
    if(nodeMid != NULL) {
        cout << "The middle node is " << nodeMid->data_ << endl;
    }

    // 反转数组
    list.reverse();
    list.print();

    return 0;
}
