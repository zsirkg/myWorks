#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main()
{
	set<string> excluded_word;
	excluded_word.insert("success");
	excluded_word.insert("class");

	vector<string> input_word;
	string word;

	cout << "Please input words to be strip plural suffixes: " << endl;
	while(cin >> word) {
		input_word.push_back(word);
	}

	vector<string>::iterator it = input_word.begin();

	while(it != input_word.end()) {
		cout << *it << " => ";
		if(!excluded_word.count(*it)) {
			it->resize(it->size() - 1);
		}
		cout << *it << endl;
		it++;
	}

	return 0;
}
