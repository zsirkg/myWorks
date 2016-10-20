#include <iostream>
#include <vector>
using namespace std;

static string prompt =
"c[n] Returns a reference to the element indexed by n.\n\
Undefined if n <0 or n >= c.size().\n\
Valid only for vector and deque. \n";

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
    int a1[] = {1, 2, 3, 4, 5};
    vector<int> ivec(a1, a1+5);

    cout << prompt;

    showVec(ivec);

    cout << "ivec[3]: " << ivec[3] << endl;

    return 0;
}
