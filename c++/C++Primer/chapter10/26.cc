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
	multimap<string, string>::iterator iter = 
		mmap_authors.find(strSearchItem);
	typedef multimap<string, string>::size_type sz_type;
	sz_type amount = mmap_authors.count(strSearchItem);
	for(sz_type cnt = 0; cnt != amount; ++cnt, ++iter) {
		cout << "we got the author: " << iter->first << endl
			<< "==>> his book: " << iter->second << endl;
	}

	amount = mmap_authors.erase(strSearchItem);
	if(amount) {
		cout << "erase " << amount << " books of this author." << endl;
	}

	return 0;
}
