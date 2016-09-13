#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	vector<int> ivec(5, 5);
	int sum;

	sum = accumulate(ivec.begin(), ivec.end(), 0);

	cout << "sum: " << sum << endl;

	return 0;
}
