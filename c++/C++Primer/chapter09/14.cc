#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s;
    vector<string> svec;

    cout << "input some strings (ctrl + D to end)" << endl;
    while(cin >> s) {
        svec.push_back(s);
    }

    cout << "you input strings are:" << endl;
    for(vector<string>::iterator it = svec.begin();
            it != svec.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}
