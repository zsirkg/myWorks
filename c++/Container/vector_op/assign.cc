#include <iostream>
#include <vector>
using namespace std;

static string prompt1 =
" c.assign(b,e) Replaces the elements in c by those in the range denoted by iterators b\n\
and e. The iterators b and e must not refer to elements in c.\n";
static string prompt2 =
"c.assign(n,t) Replaces the elements in c by n elements with value t.\n";

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

    cout << prompt1;

    cout << "ivec1: ";
    showVec(ivec1);
    cout << "ivec2: ";
    showVec(ivec2);

    cout << "ivec1.assign(ivec2.begin(), ivec2.begin() + 2);" << endl;
    ivec1.assign(ivec2.begin(), ivec2.begin() + 2);
    cout << "ivec1: ";
    showVec(ivec1);
    cout << "ivec2: ";
    showVec(ivec2);

    cout << prompt2;
    cout << "ivec1.assign(2, 9);" << endl;
    ivec1.assign(2, 9);
    cout << "ivec1: ";
    showVec(ivec1);

    return 0;
}
