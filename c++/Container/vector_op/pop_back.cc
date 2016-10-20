#include <iostream>
#include <vector>
using namespace std;

static string prompt =
"c.pop_back() Removes the last element in c. Returns void. Undefined if c is empty. \n";

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

    cout << "ivec.pop_back()" << endl;
    ivec.pop_back();
    showVec(ivec);

    return 0;
}
