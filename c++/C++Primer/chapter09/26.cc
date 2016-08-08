#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    int ia[] = { 0, 1, 2, 2, 3, 5, 8, 13, 21, 55, 89 };
    vector<int> ivec(ia, ia+11);
    list<int> ilist(ia, ia+11);

    for(int ix = 0; ix < 11; ix++) {
        cout << ia[ix] << " ";
    }
    cout << endl;

    for(vector<int>::iterator it = ivec.begin();
            it != ivec.end(); it++) {
        if(*it % 2 == 0) {
            it = ivec.erase(it);
            it--; /*由于返回删除元素的下一个元素*/
        }
    }
    for(vector<int>::iterator it = ivec.begin();
            it != ivec.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    for(list<int>::iterator it = ilist.begin();
            it != ilist.end(); it++) {
        if(*it % 2 == 1) {
            it = ilist.erase(it); 
            it--; /*由于返回删除元素的下一个元素*/
        }
    }
    for(list<int>::iterator it = ilist.begin();
            it != ilist.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    return 0;
}
