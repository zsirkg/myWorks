#include <iostream>
#include <vector>
using namespace std;

static string prompt =
"set vector capacity.\n";

void showVec(const vector<int>& ivec)
{
    int count = ivec.size();
    for (int i = 0; i < count;i++)
    {
        cout << ivec[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << prompt;

    vector<int> ivec1;
    cout << "ivec1:";
    showVec(ivec1);
    cout << "ivec1.capacity(): " << ivec1.capacity() << endl;

    cout << "ivec1.reserve(50): " << endl;
    ivec1.reserve(50);
    cout << "ivec1.capacity(): " << ivec1.capacity() << endl;

    return 0;
}
