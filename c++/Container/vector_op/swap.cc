#include <iostream>
#include <vector>
using namespace std;

static string prompt =
"c1.swap(c2) Swaps contents: After the call c1 has elements that were in c2, and c2 has\n\
elements that were in c1. c1 and c2 must be the same type. Execution time\n\
usually much faster than copying elements from c2 to c1.\n";

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
    int a2[] = {5, 4, 3, 2, 1};
    vector<int> ivec1(a1, a1+5);
    vector<int> ivec2(a2, a2+5);

    cout << prompt;

    cout << "ivec1: ";
    showVec(ivec1);
    cout << "ivec2: ";
    showVec(ivec2);

    ivec1.swap(ivec2);
    cout << "ivec1.swap(ivec2);" << endl;

    cout << "ivec1: ";
    showVec(ivec1);
    cout << "ivec2: ";
    showVec(ivec2);

    return 0;
}
