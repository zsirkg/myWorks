#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str;
	int iVal;
	pair<string, int> newPair;

	vector< pair<string, int> > pairVec;

	//while(cin >> str >> iVal) {
		// first method
		//pairVec.push_back(pair<string, int>(str, iVal));
		
		// second method
		//newPair = make_pair(str, iVal);
		//pairVec.push_back(newPair);
	//}

	// third method
	while(cin >> newPair.first >> newPair.second) {
		pairVec.push_back(newPair);
	}



	for(vector< pair<string, int> >::iterator iter = pairVec.begin();
			iter != pairVec.end(); iter++) {
		cout << iter->first << " " << iter->second << endl;
	}

	return 0;
}

