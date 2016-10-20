#include <iostream>
#include <vector>
using namespace std;

static string prompt =
"c.clear() Removes all the elements in c. Returns void.\n";

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

    cout << "ivec.clear();" << endl;
    ivec.clear();
    showVec(ivec);

    return 0;
}
