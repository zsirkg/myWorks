#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

bool greaterThan4(const string &s)
{
	return s.size() >= 4;
}

int main()
{
	string astr[]={"the", "quick", "red", "fox",
		"jumps", "over", "the", "slow", "red", "turtle"};
	
	size_t cnt = sizeof(astr)/sizeof(string);
	vector<string> svec(astr, astr+cnt);

	cout << "origin: " << endl;
	for(vector<string>::iterator it = svec.begin();
			it != svec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	cout << "after sort: " << endl;
	sort(svec.begin(), svec.end());
	for(vector<string>::iterator it = svec.begin();
			it != svec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	cout << "after unique: " << endl;
	vector<string>::iterator end_unique = unique(svec.begin(), svec.end());
	for(vector<string>::iterator it = svec.begin();
			it != svec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	cout << "after erase: " << endl;
	svec.erase(end_unique, svec.end());
	for(vector<string>::iterator it = svec.begin();
			it != svec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	cout << "after shorter: " << endl;
	stable_sort(svec.begin(), svec.end(), isShorter);
	for(vector<string>::iterator it = svec.begin();
			it != svec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	cout << "after size >= 4: " << endl;
	vector<string>::size_type wc = 
		count_if(svec.begin(), svec.end(), greaterThan4);
	cout << wc << " words" << " size 4 or greater." << endl;


	return 0;
}
