#ifndef __30_H__
#define __30_H__

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class TextQuery {
	public:
		TextQuery();
		~TextQuery();
		typedef vector<string>::size_type line_no;
		void read_file(ifstream &is)
			{store_file(is); build_map();}
		set<line_no> run_query(const string&) const;
		string text_line(line_no) const;

	private:
		void store_file(ifstream &);
		void build_map();
		vector<string> line_of_text;
		map<string, set<line_no> > word_map;
};

#endif
