#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

int main()
{
    int ia[7] = {0, 1, 1, 2, 3, 5, 8};
    string sa[6] = {
        "Fort Sumter", "Manassas", "Perryville"
        "Vicksburg", "Meridiab", "Chancellorsville"
    };

    vector<string> svec(sa, sa+6);
    list<int> ilist(ia+4, ia+6);
    //vector<int> ivec(ia, ia+8); //error, overflow
    //list<string> slist(sa+6, sa); //error, start > end -- logic error

    list<int>::iterator iter;
    for(iter = ilist.begin(); iter != ilist.end(); iter++) {
        cout << *iter << endl;
    }
    vector<string>::iterator iter1;
    for(iter1 = svec.begin(); iter1 != svec.end(); iter1++) {
        cout << *iter1 << endl;
    }

    return 0;
}
