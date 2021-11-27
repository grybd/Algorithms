#include <iostream>
#include <string>
#include<unordered_set>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    char c;
    cin>>c;
    unordered_multiset<char> set;
    for (char a : s) {
        set.insert(tolower(a));
    }
    int n=set.count(tolower(c));
    cout << n << endl;
}
