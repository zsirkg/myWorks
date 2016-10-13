#include <iostream>
#include <vector>
#include <set>
using namespace std;

void intersection(vector<int> &ivecA, vector<int> &ivecB, vector<int> &ivecC)
{
    set<int> iset;

    for(vector<int>::iterator iter = ivecA.begin(); iter != ivecA.end();
            iter++) {
        iset.insert(*iter);
    }

    for(vector<int>::iterator iter = ivecB.begin(); iter != ivecB.end();
            iter++) {
        if(iset.find(*iter) != iset.end()) {
            ivecC.push_back(*iter);
        }
    }

}

int main()
{
    int i;
    vector<int> ivecA;
    vector<int> ivecB;
    vector<int> ivecC;

    cout << "input ivecA:" << endl;
    while(cin >> i) {
        ivecA.push_back(i);
    }

    cin.clear();
    cout << "input ivecB:" << endl;
    while(cin >> i) {
        ivecB.push_back(i);
    }

    cout << "input ivecA:";
    for(vector<int>::iterator iter = ivecA.begin(); iter != ivecA.end();
            iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    cout << "input ivecB:";
    for(vector<int>::iterator iter = ivecB.begin(); iter != ivecB.end();
            iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    cout << "intersection of ivecA and ivecB:";
    intersection(ivecA, ivecB, ivecC);
    for(vector<int>::iterator iter = ivecC.begin(); iter != ivecC.end();
            iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}
