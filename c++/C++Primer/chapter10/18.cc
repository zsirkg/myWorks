#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main()
{
	map< string, vector<string> > children;
	string famName, childName;

	do {
		cout << "Input families' name(ctrl + d to end):"
			<< endl;
		cin >> famName;
		if(!cin)
			break;

		vector<string> chd;
		pair< map<string, vector<string> >::iterator, bool> ret =
			children.insert(make_pair(famName, chd));	
		if(!ret.second) {
			cout << "alread exist family name: " << famName << endl;
			continue;
		}

		cout << "input chidren's name of family " << famName << endl;
		while(cin >> childName)
			ret.first->second.push_back(childName);

		cin.clear();
		

	} while(cin);

	cin.clear();

	cout << "input a family name to search: ";
	cin >> famName;
	map< string, vector<string> >::iterator map_it = children.find(famName);
	if(map_it != children.end()) {
		for(vector<string>::iterator it = map_it->second.begin();
				it != map_it->second.end(); it++) {
			cout << *it << endl;
		}
	}

	return 0;
}
