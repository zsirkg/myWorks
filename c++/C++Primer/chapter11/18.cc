#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
    ofstream outFile_odd, outFile_even;
    outFile_odd.open("odd_data");
    outFile_even.open("even_data");

    if(!outFile_odd || !outFile_even) {
        return -1;
    }

    istream_iterator<int> in_iter(cin), eof;
    ostream_iterator<int> out_odd_iter(outFile_odd, " ");
    ostream_iterator<int> out_even_iter(outFile_even, "\n");

    while(in_iter != eof) {
        if(*in_iter % 2 == 1) {
            *out_odd_iter++ = *in_iter++;
        } else {
            *out_even_iter++ = *in_iter++;
        }
    }

    outFile_odd.close();
    outFile_even.close();
    cout << endl;

    return 0;
}
