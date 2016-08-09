#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> ivec;

    cout << "ivec.size()" << ivec.size() << endl
         << "ivec.capacity()" << ivec.capacity() << endl;
    while(ivec.size() != ivec.capacity()) {
        ivec.push_back(0);
    }
    ivec.push_back(0);
    cout << "ivec.size()" << ivec.size() << endl
         << "ivec.capacity()" << ivec.capacity() << endl;

    ivec.reserve(20);
    cout << endl << "ivec.size()" << ivec.size() << endl
         << "ivec.capacity()" << ivec.capacity() << endl;
    while(ivec.size() != ivec.capacity()) {
        ivec.push_back(0);
    }
    ivec.push_back(0);
    cout << "ivec.size()" << ivec.size() << endl
         << "ivec.capacity()" << ivec.capacity() << endl;

    ivec.reserve(114);
    cout << endl << "ivec.size()" << ivec.size() << endl
         << "ivec.capacity()" << ivec.capacity() << endl;
    while(ivec.size() != ivec.capacity()) {
        ivec.push_back(0);
    }
    ivec.push_back(0);
    cout << "ivec.size()" << ivec.size() << endl
         << "ivec.capacity()" << ivec.capacity() << endl;


    return 0;
}
