#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings_(string s) {
      vector<int> res(s.length(),-1);
      return getAns(s,0,res);
    }
private:
    //利用memoization技术优化递归
    int getAns(string s,int start,vector<int>&res){
      if(start>=(int)s.length()) return 1;
      if(s[start]=='0') return 0;
      if(res[start]!=-1) return res[start];
      int ans1 = getAns(s,start+1,res);
      int ans2 = 0;
      if(start<(int)s.length()-1){
        int ten = (s[start]-'0')*10;
        int one = s[start+1]-'0';
        if(ten+one<=26){
          ans2=getAns(s,start+2,res);
        }
      }
      res[start]=ans1+ans2;
      return ans1+ans2;
    }
};
