#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	vector<int> ivec;

#if 0
	fill_n(back_inserter(ivec), 10, 0);
#else
	ivec.resize(10);
	fill_n(ivec.begin(), 10, 0);
#endif

	for(vector<int>::iterator it = ivec.begin();
			it != ivec.end(); it++) {
		cout << *it << " ";
	}

	cout << endl;

	return 0;
}
