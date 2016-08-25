#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string, int> word_count;
	string word;

	while(cin >> word) {
		pair<map<string, int>::iterator, bool> ret = 
			word_count.insert(make_pair(word, 1));
		if(!ret.second) {
			++ret.first->second;
		}
		cout << ret.second << " " << word << " " << ret.first->second << endl;
	}

	return 0;
}
