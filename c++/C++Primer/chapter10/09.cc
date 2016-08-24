#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string, int> word_count;
	string word;

	while(cin >> word) {
		++word_count[word];
	}

	for(map<string, int>::iterator miter = word_count.begin();
		   miter != word_count.end(); miter++) {
		cout << miter->first << " " << miter->second << endl;
	}


	return 0;
}
