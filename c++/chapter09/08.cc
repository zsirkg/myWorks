#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> svec;
    vector<string>::iterator iter = svec.begin();

    //cout << "iter->empty() = " << iter->empty() << endl; // segmentation fault
    cout << "iter->empty() = " << svec.empty() << endl;
    return 0;
}
