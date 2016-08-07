#include <iostream>
#include <vector>
using namespace std;

typedef vector<int>::iterator ivecIter;
ivecIter find_integer(ivecIter first, ivecIter last, int target)
{
    if(first > last) {
        cout << "iterator error" << endl;
    }

    ivecIter iter = first;
    for(;iter != last; iter++) {
        if(*iter == target) {
            break;
        }
    }

    return iter;
}

int main()
{
    int ia[5] = {0, 1, 2, 3, 4};
    vector<int> ivec(ia, ia + 5);

    ivecIter iter;
    iter = find_integer(ivec.begin(), ivec.end(), 5);
    if(iter != ivec.end()) {
        cout<< "find" << endl;
    } else {
        cout<< "not find" << endl;
    }

    return 0;
}
