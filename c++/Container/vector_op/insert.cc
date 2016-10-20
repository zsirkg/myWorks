#include <iostream>
#include <vector>
using namespace std;

static string prompt1 =
"c.insert(p,t) Inserts element with value t before the element referred to by iterator\n\
p. Returns an iterator referring to the element that was added.\n";
static string prompt2 =
"c.insert(p,n,t) Inserts n elements with value t before the element referred to by\n\
iterator p. Returns void.\n";
static string prompt3 =
"c.insert(p,b,e) Inserts elements in the range denoted by iterators b and e before the\n\
element referred to by iterator p. Returns void.\n";

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

    ivec.insert(ivec.begin() + 2, 9);
    cout << "ivec.insert(ivec.begin() + 2, 9)" << endl;
    showVec(ivec);

    cout << prompt2;
    ivec.insert(ivec.begin() + 2, 2, 8);
    cout << "ivec.insert(ivec.begin() + 2, 2, 8)" << endl;
    showVec(ivec);

    cout << prompt3;
    ivec.insert(ivec.begin(), ivec.begin(), ivec.begin() + 2);
    cout << "ivec.insert(ivec.begin(), ivec.begin(), ivec.begin() + 2)" << endl;
    showVec(ivec);

    return 0;
}
