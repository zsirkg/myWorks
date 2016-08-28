#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	multimap<string, string> mmap_authors;
	string author, book;
	
	cout << "input autho and his book:" << endl;
	while(cin >> author >> book) {
		mmap_authors.insert(make_pair(author, book));
	}

	string strSearchItem;
	cout << "Input which author do you want to search: ";
	cin.clear();
	cin >> strSearchItem;

	typedef multimap<string, string>::iterator mmap_it;
	typedef multimap<string, string>::size_type sz_type;
	pair<mmap_it, mmap_it> pos = mmap_authors.equal_range(strSearchItem);

	mmap_it it  = pos.first;
	while(it != pos.second) {
		cout << "we got the author: " << it->first << endl
			<< "==>> his book: " << it->second << endl;
		++it;
	}

	sz_type amount = mmap_authors.count(strSearchItem);
	mmap_authors.erase(pos.first, pos.second);
	if(amount) {
		cout << "delete " << amount << " books" << endl;
	}

	for(mmap_it iter = mmap_authors.begin();
			iter != mmap_authors.end(); iter++) {
		cout << iter->first << " " << iter->second << endl;
	}
	

	return 0;
}
