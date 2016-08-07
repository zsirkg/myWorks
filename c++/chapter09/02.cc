#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int ia[3] = {0, 1, 2};

    vector<int> ivec1(6);
    vector<int> ivec2(ia, ia+3);
    vector<int> ivec3(ivec2);
    vector<int> ivec4(6, 6);

    cout << "==>int ia[3] = {0, 1, 2}<==" << endl;
    cout << "==>vector<int> ivec1(6)<==" << endl;
    for(vector<int>::iterator iter = ivec1.begin(); iter != ivec1.end(); iter++) {
        cout << *iter << endl;
    }

    cout << "==>vector<int> ivec2(ia, ia+3)<==" << endl;
    for(vector<int>::iterator iter = ivec2.begin(); iter != ivec2.end(); iter++) {
        cout << *iter << endl;
    }

    cout << "==>vector<int> ivec3(ivec2)<==" << endl;
    for(vector<int>::iterator iter = ivec3.begin(); iter != ivec3.end(); iter++) {
        cout << *iter << endl;
    }

    cout << "==>vector<int> ivec4(6, 6)<==" << endl;
    for(vector<int>::iterator iter = ivec4.begin(); iter != ivec4.end(); iter++) {
        cout << *iter << endl;
    }
    return 0;
}

