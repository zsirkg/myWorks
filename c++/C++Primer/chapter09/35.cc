#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s("helloHH world!");

    cout << s << endl;
    string::iterator it;
    for(it = s.begin(); it != s.end(); it++) {
        if(isupper(*it)) {
            s.erase(it);
            it--;
        }
    }
    cout << s << endl;

    return 0;
}
