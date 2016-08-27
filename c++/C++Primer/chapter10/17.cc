#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int main(int argc, char **argv)
{
	map<string, string> trans_map;
	string key, value;
	
	if(argc != 3)
		cout << "argc invalid, must 3" << endl;

	ifstream map_file(argv[1]);
	if(!map_file.is_open())
		return -1;

	while(map_file >> key >> value)
		trans_map.insert(make_pair(key, value));


	ifstream input_file(argv[2]);
	if(!input_file.is_open())
		return -1;

	string line;
	while(getline(input_file, line)) {
		istringstream stream(line);
		string word;
		bool firstword = true;
		while(stream >> word) {
			map<string, string>::iterator map_it = trans_map.find(word);
			if(map_it != trans_map.end()) {
				word = map_it->second;
				if(firstword)
					firstword = false;
				else
					cout << " ";
				cout << word;
			}
		}
		cout << endl;
	}

	return 0;
}
