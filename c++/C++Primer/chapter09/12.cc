#include <iostream>
#include <vector>
using namespace std;

bool find_integer(vector<int>::iterator first,
        vector<int>::iterator last, int target)
{
    if(first > last) {
        cout << "iterator error" << endl;
    }
    for(vector<int>::iterator iter = first;
            iter != last; iter++) {
        if(*iter == target) {
            return true;
        }
    }

    return false;
}

int main()
{
    int ia[5] = {0, 1, 2, 3, 4};
    vector<int> ivec(ia, ia + 5);

    cout<< find_integer(ivec.begin(), ivec.end(), 4) << endl;

    return 0;
}
