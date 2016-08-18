#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string separators(" :\t,\v\r\n\f");
    string line1 = "We were her pride of 10 she named us:";
    string line2 = "Benjamin, Phoenix, the Prodigal";
    string line3 = "and perspicacious pacific Suzanne";
    string sentence = line1 + ' ' + line2 + ' ' + line3;

    string::size_type startPos = 0, endPos = 0;
    string::size_type maxLen, minLen, wordLen;
    size_t wordCount;
    string word;
    vector<string> longestWords, shortestWords;

    wordCount = 0;
    cout << sentence << endl;

    while((startPos = sentence.find_first_not_of(separators, endPos)) != string::npos) {
		++wordCount;
        endPos = sentence.find_first_of(separators, startPos);
		if(endPos == string::npos) {
			wordLen = sentence.size() - startPos;
		} else {
			wordLen = endPos - startPos;
		}
        
        word.assign(sentence, startPos, wordLen);
        cout << "word: " << word << " len: " << wordLen << endl;

        if(wordCount == 1) {
			maxLen = minLen = wordLen;
            longestWords.push_back(word);
			shortestWords.push_back(word);
		} else {
			if(wordLen > maxLen) {
				maxLen = wordLen;
				longestWords.clear();
				longestWords.push_back(word);
			} else if(wordLen == maxLen) {
				longestWords.push_back(word);
			}

			if(wordLen < minLen) {
				minLen = wordLen;
				shortestWords.clear();
				shortestWords.push_back(word);
			} else if (wordLen == minLen){
				shortestWords.push_back(word);
			}
		}
    }

    cout << "There are " << wordCount << " in the sentence." << endl;
    cout << "longest Word length:" << longestWords.front().size() <<endl;
    cout << "longest Words:" << endl;
    for(vector<string>::iterator it = longestWords.begin(); it != longestWords.end(); it++) {
        cout << *it << endl;
    }

    cout << "shortest Word length:" << shortestWords.front().size() <<endl;
    cout << "shortest Words:" << endl;
    for(vector<string>::iterator it = shortestWords.begin(); it != shortestWords.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}
