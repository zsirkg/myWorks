#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	pair<string, int> siPair;
	vector< pair<string, int> > sipVec;

	while(cin >> siPair.first >> siPair.second) {
		sipVec.push_back(siPair);
	}

	for(vector< pair<string, int> >::iterator iter = sipVec.begin();
			iter != sipVec.end(); iter++) {
		cout << iter->first << " " << iter->second << endl;
	}

	return 0;
}

