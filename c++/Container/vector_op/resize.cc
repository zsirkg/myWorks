#include <iostream>
#include <vector>
using namespace std;

static string prompt1 =
"c.resize(n) Resize c so that it has n elements. If N < c.size(), the excess elements are\n \
discarded. If new elements must be added, they are value initialized. \n";

static string prompt2 =
"c.resize(n,t) Resize c to have n elements. Any elements added have value t.\n";

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

    cout << prompt1;

    showVec(ivec);

    cout << "resize(6):" << endl;
    ivec.resize(6);
    showVec(ivec);

    cout << "resize(4):" << endl;
    ivec.resize(4);
    showVec(ivec);

    cout << prompt2;
    cout << "resize(6, 9):" << endl;
    ivec.resize(6, 9);
    showVec(ivec);

    return 0;
}
