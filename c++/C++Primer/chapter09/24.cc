#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> ivec1;

    int i;
    cout << "input integer to ivec1" << endl;
    while(cin >> i) {
        ivec1.push_back(i);
    }

    if(!ivec1.empty()) {
        cout << "ivec1[0] = " << ivec1[0] << endl;
        cout << "ivec1.front() = " << ivec1.front() << endl;
        cout << "ivec1.begin() = " << *ivec1.begin() << endl;
        cout << "ivec1.at(0) = " << ivec1.at(0) << endl;
    } else {
        cout << "ivec1 is empty" << endl;
    }

    return 0;
}
