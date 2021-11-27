#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
      return compareString(s)==compareString(t);
    }
private:
    string compareString(string&s){
      string temp;
      int n=s.size();
      for(int i=0;i<n;i++){
        if(s[i]!='#') temp.push_back(s[i]);
        else if(!s.empty()&&s[i]=='#') temp.pop_back();
      }
      return temp;
    }
};
