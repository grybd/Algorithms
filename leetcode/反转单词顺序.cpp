#include <string>
#include <sstream>
#include <stack>
using namespace std;

class Solution
{
public:
  string reverseWords(string s)
  {
    stack<string> stk;
    string res,str;
    istringstream ss(s);
    while(ss>>str) stk.push(str),stk.push(" ");
    if(!stk.empty()) stk.pop();
    while(!stk.empty()) res+=stk.top(),stk.pop();
    return res;
  }  
};
