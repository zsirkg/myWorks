#include <list>
#include <iostream>
using namespace std;

int main()
{
    list<int> lst1(5, 1);
    list<int>::iterator iter1=lst1.begin(), iter2=lst1.end();

    while(iter1 != iter2) {
        cout << *iter1 << endl;

        iter1++;
    }

    return 0;
}
