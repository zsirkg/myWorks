#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> ilist;
    list<int>::iterator iter;

    for(int i = 0; i != 10; i++) {
        ilist.push_back(i);
    }

    iter = ilist.end();
    iter--;
    for(; iter != ilist.begin(); iter--) {
        cout << *iter << endl;
    }
    cout << *iter << endl;

    return 0;
}
