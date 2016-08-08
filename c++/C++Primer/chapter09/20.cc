#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    int ia[] = {1, 2, 3};
    vector<int> ivec1(ia, ia+3);
    list<int> ilist(ia, ia+3);
    vector<int> ivec2(ilist.begin(), ilist.end());

    if(ivec1 == ivec2) {
        cout << "same" << endl;
    } else {
        cout << "different" << endl;
    }

    return 0;
}
