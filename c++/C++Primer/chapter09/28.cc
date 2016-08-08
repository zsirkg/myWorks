#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    char *c_arr[] = {"c style string1", "c style string2", "c style string3"};
    list<char *> cslist(c_arr, c_arr+3);
    vector<string> svec;

    svec.assign(cslist.begin(), cslist.end());

    for(vector<string>::iterator it = svec.begin();
            it != svec.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}
