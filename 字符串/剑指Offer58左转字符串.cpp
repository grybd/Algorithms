#include <string>
#include <vector>
#include <stack>
using namespace std;


  class Solution{
    public:
      string reverseLeftWords(string s,int n){
        if(n==0||(int)s.size()<n) return s;
        string s1="";
        string s2="";
        for(int i=0;i<n;i++){
          s1+=s[i];
        }
        for(int j=n;j<(int)s.size();j++){
          s2+=s[j];
        }
        string ans = s2+s1;
        return ans;
      }
 };
