#include <iostream>
#include <vector>
using namespace std;

static string prompt =
"c.front() Returns a reference to the first element in c. Undefined if c is empty.\n";

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

    cout << "front: " << ivec.front() << endl;

    return 0;
}
