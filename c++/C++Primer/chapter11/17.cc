#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    istream_iterator<int> cin_it(cin), eof;
    vector<int> ivec(cin_it, eof);

    for(vector<int>::iterator it = ivec.begin();
            it != ivec.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}
