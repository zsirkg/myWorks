#include <iostream>
#include <vector>
using namespace std;

static string prompt =
"c.push_back(t) Adds element with value t to the end of c. Returns void.\n";

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

    ivec.push_back(6);
    cout << "ivec.push_back(6)" << endl;
    showVec(ivec);

    return 0;
}
