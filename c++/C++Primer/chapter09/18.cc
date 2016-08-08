#include <iostream>
#include <list>
#include <deque>
using namespace std;

int main()
{
    int ia[] = {11, 12, 13, 14, 15, 16, 17};
    list<int> ilist(ia, ia+7);
    deque<int> evenDeque;
    deque<int> oddDeque;

    for(list<int>::iterator it = ilist.begin();
            it != ilist.end(); it++) {
        if(*it % 2 == 0) {
            evenDeque.push_back(*it);
        } else {
            oddDeque.push_back(*it);
        }
    }

    cout << "even deque:" << endl;
    for(deque<int>::iterator it = evenDeque.begin();
            it != evenDeque.end(); it++) {
        cout << *it << " ";
    
    }
    cout << endl;

    cout << "odd deque:" << endl;
    for(deque<int>::iterator it = oddDeque.begin();
            it != oddDeque.end(); it++) {
        cout << *it << " ";
    
    }
    cout << endl;

    

    return 0;
}

