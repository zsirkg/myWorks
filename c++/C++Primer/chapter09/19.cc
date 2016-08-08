#include <iostream>
#include <vector>
using namespace std;

const int some_val = 2;
int main()
{
    int ia[] = {1, 2, 3, 4, 5, 6};
    vector<int> ivec(ia, ia+6);
    vector<int>::iterator it = ivec.begin(); 

    while(it != ivec.begin() + ivec.size()/2) {
        if(*it == some_val) {
            it = ivec.insert(it, some_val * 2);
            it += 2;
        } else {
            it++;
        }
    }

    for(vector<int>::iterator it = ivec.begin();
           it != ivec.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
