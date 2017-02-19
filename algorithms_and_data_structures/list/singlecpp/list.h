#ifndef __LIST_H__
#define __LIST_H__

class Node {
public:
    Node(int i):data_(i) {}

    int data_;
    Node *next_;
};

class List {
public:
    List();
    ~List();

    void insertNode(Node *node);
    void reverse();
    Node* getRK(int k);
    Node* getMiddle();
    bool hasCircle();
    Node* getFirstNodeInCircle();
    void print();
    void printReverse();
    void printReverseRecursion();
private:
    Node *head_;
};

#endif
