#include <iostream>
#include <string>
using namespace std;

int main()
{
    string strSearchVal("ab0c1d2E3F4");
    string numerics("0123456789");
    string::size_type pos = 0;

    cout << "origin string: " << strSearchVal << endl;
    cout << "numerics" << endl;
    while( (pos = strSearchVal.find_first_of(numerics, pos)) != string::npos) {
        cout << strSearchVal[pos];
        ++pos;
    }

    cout << endl << "character" << endl;
    pos = 0;
    while( (pos = strSearchVal.find_first_not_of(numerics, pos)) != string::npos) { //非数字，但不保证一定为英文字母
        cout << strSearchVal[pos];
        ++pos;
    }
    cout << endl;

    return 0;
}
