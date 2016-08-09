#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<char> cVec;
    char cVal;
    
    while(cin >> cVal) {
        cVec.push_back(cVal);
    }

    string s(cVec.begin(), cVec.end());
    cout << s << endl;

    return 0;
}
