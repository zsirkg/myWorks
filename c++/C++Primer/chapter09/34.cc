#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s("hello world!");

    cout << s << endl;
    string::iterator it;
    for(it = s.begin(); it != s.end(); it++) {
        *it = toupper(*it);
    }
    cout << s << endl;

    return 0;
}
