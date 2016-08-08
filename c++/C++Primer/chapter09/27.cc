#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string sval("hit");
    string sa[] = {"hello", "world", "hit"};
    list<string> slist(sa, sa + 3);
    list<string>::iterator elem;

    elem = find(slist.begin(), slist.end(), sval);
    if(elem == slist.end()) {
        cout << "can't find " << sval << endl;
        return -1;
    }

    slist.erase(elem);
    for(list<string>::iterator it = slist.begin();
            it != slist.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}
