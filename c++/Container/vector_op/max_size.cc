#include <iostream>
#include <vector>
using namespace std;

static string prompt =
"c.max_size() Returns maximum number of elements c can contain. Return type is c::size_type.\n";

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

    cout << "max_size: " << ivec.max_size() << endl;

    return 0;
}
