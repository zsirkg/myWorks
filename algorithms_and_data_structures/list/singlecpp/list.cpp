#include <iostream>
#include <stack>
#include "list.h"
using namespace std;

List::List()
{
    head_ = NULL;
}

List::~List()
{
    Node *cur = head_;

    while(cur != NULL) {
        Node *tmp = cur;
        cur = cur->next_;
        delete tmp;
    }

    head_ = NULL;
}

void List::insertNode(Node *node)
{
    node->next_ = head_;
    head_ = node;
}

void List::reverse()
{
    if(head_ == NULL || head_->next_ == NULL) {
        return;
    }

    Node *cur = head_;
    Node *reverseHead = NULL;
    while(cur != NULL) {
        Node *tmp = cur;
        cur = cur->next_;
        tmp->next_ = reverseHead;
        reverseHead = tmp;
    }

    head_ = reverseHead;
}

Node* List::getRK(int k)
{
    if(head_ == NULL || k < 1) {
        return NULL;
    }

    Node *cur = head_;
    while(k > 1 && cur != NULL) {
        cur = cur->next_;
        k--;
    }

    if(k > 1 || cur == NULL) {
        cout << "list length too short " << endl;
        return NULL;
    }

    Node *nodeRK = head_;
    while(cur->next_ != NULL) {
        cur = cur->next_;
        nodeRK = nodeRK->next_;
    }

    return nodeRK;
}

Node* List::getMiddle()
{
    if(head_ == NULL && head_->next_) {
        return head_;
    }

    Node* cur = head_;
    Node* mid = head_;
    while(cur->next_ != NULL && cur->next_->next_ != NULL) {
        cur = cur->next_->next_;
        mid = mid->next_;
    }

    return mid;
}

bool List::hasCircle()
{
    if(head_ == NULL) {
        return false;
    }

    Node* fast = head_;
    Node* slow = head_;
    while(fast != NULL && fast->next_ != NULL) {
        fast = fast->next_->next_;
        slow = slow->next_;
        if(fast == slow) {
            return true;
        }
    }

    return false;
}

Node* List::getFirstNodeInCircle()
{
    if(head_ == NULL && head_->next_ == NULL) {
        return NULL;
    }

    Node* fast = head_;
    Node* slow = head_;
    while(fast != NULL && fast->next_ != NULL) {
        fast = fast->next_->next_;
        slow = slow->next_;
        if(fast == slow) {
            break;
        }
    }

    if(fast == NULL || fast->next_ == NULL) {
        return NULL;
    }

    Node* assumedTail = slow;
    Node* head1 = head_;
    Node* head2 = assumedTail->next_;

    Node* node1 = NULL;
    Node* node2 = NULL;

    node1 = head1;
    node2 = head2;
    int len1 = 1;
    while(node1 != assumedTail) {
        node1 = node1->next_;
        len1++;
    }

    int len2 = 1;
    while(node2 != assumedTail) {
        node2 = node2->next_;
        len2++;
    }

    node1 = head1;
    node2 = head2;

    int k = 0;
    if(len1 > len2) {
        k = len1 - len2;
        while(k--) {
            node1 = node1->next_;
        }
    } else {
        k = len2 - len1;
        while(k--) {
            node2 = node2->next_;
        }
    }

    while(node1 != node2) {
        node1 = node1->next_;
        node2 = node2->next_;
    }

    return node1;
}

void List::print()
{
    Node *cur = head_;
    /* Node *pre; */

    while(cur != NULL) {
        cout << cur->data_ << " ";
        /* pre = cur; */
        cur = cur->next_;
    }

    /* pre->next_ = head_->next_; */
    cout << endl;
}

void List::printReverse()
{
    std::stack<Node*> nodeStack;

    Node* cur = head_;
    while(cur != NULL) {
        nodeStack.push(cur);
        cur = cur->next_;
    }

    while(!nodeStack.empty()) {
        cur = nodeStack.top();
        cout << cur->data_ << " ";
        nodeStack.pop();
    }
    cout << endl;
}

static void printReverseRecursion_(Node *node)
{
    if(node == NULL) {
        return;
    }

    printReverseRecursion_(node->next_);
    cout << node->data_ << " ";
}

void List::printReverseRecursion()
{
    printReverseRecursion_(head_);
    cout << endl;
}
