#include <iostream>
#include <vector>
using namespace std;

static string prompt =
"c.size() Returns the number of elements in c. Return type is c::size_type.\n";

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

    cout << "size: " << ivec.size() << endl;

    return 0;
}
