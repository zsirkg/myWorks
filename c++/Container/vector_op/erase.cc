#include <iostream>
#include <vector>
using namespace std;

static string prompt1 =
"c.erase(p) Removes element referred to by the iterator p.\n\
Returns an iterator referring to the element after the one deleted, or an\n\
off-the-end iterator if p referred to the last element. Undefined if p is an\n\
off-the-end iterator.\n";

static string prompt2 =
"c.erase(b,e) Removes the range of elements denoted by the iterators b and e.\n\
Returns an iterator referring after the last one in the range that was deleted,\n\
or an off-the-end iterator if e is itself an off-the-end iterator.\n";

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
    cout << prompt2;

    showVec(ivec);

    cout << "ivec.erase(ivec.begin())" << endl;
    ivec.erase(ivec.begin());
    showVec(ivec);

    cout << "ivec.erase(ivec.begin(), ivec.begin()+2)" << endl;
    ivec.erase(ivec.begin(), ivec.begin() + 2);
    showVec(ivec);

    return 0;
}
