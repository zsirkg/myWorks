#include "30.h"

TextQuery::TextQuery()
{

}

TextQuery::~TextQuery()
{

}

void TextQuery::store_file(ifstream &is)
{
	string line;
	while(getline(is, line)) {
		line_of_text.push_back(line);
	}
}

void TextQuery::build_map()
{
	string word;
	for(line_no no = 0; no != line_of_text.size(); no++) {
		istringstream line(line_of_text[no]);
		while(line >> word) {
			word_map[word].insert(no);
		}
	}
}

set<TextQuery::line_no> TextQuery::run_query(const string& query_word) const
{
	map<string, set<line_no> >::const_iterator map_it = word_map.find(query_word);

	if(map_it != word_map.end()) {
		return map_it->second;
	}

	return set<line_no> ();
}


string TextQuery::text_line(line_no line) const
{
	if(line < line_of_text.size()) {
		return line_of_text[line];
	}	

	throw std::out_of_range("line number out of range.");
}

string make_plural(size_t ctr, const string &word,
		const string &ending)
{
	return (ctr == 1) ? word : word + ending;
} 

void printf_result(const set<TextQuery::line_no>& locs, 
		const string& sought, const TextQuery &file)
{
	typedef set<TextQuery::line_no> line_nums;
	line_nums::size_type size = locs.size();
	
	cout << "\n" << sought << " occurs "
		<< size << make_plural(size, "time", "s") << endl;

	line_nums::const_iterator it = locs.begin();
	for(;it != locs.end(); it++) {
		cout << "\t(line"
			<< (*it) + 1 << ")"
			<< file.text_line(*it) << endl;
	}
}

int main()
{
	TextQuery tq;

	ifstream fin("data");
	tq.read_file(fin);
	while(true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		cin >> s;
		if(!cin || s == "q") break;
		set<TextQuery::line_no> locs = tq.run_query(s);
		printf_result(locs, s, tq);
	}

	return 0;
}
