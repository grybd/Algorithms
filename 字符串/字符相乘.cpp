#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    string multiply(string num1,string num2){
      if(num1=="0"||num2=="0") return "0";
      int m=num1.size(),n=num2.size(),add=0;
      string ans="";
      for(int i=n-1;i>=0;i--){
        string tmp;
        for(int j=n-1;j>i;j--){
          tmp.push_back('0');
        }
        int x=num2[i]-'0';
        for(int j=m-1;j>=0;j--){
          int y=num1[j]-'0';
          int result = y+x+add;
          tmp.push_back(result%10+'0');
          add=result/10;
        }
        ans = stringsadd(ans,tmp);
      }
      return ans;
    }
  string stringsadd(string num1,string num2){
    int i=num1.size()-1,j=num2.size()-1,add=0;
    string ans;
    while(i>=0||j>=0||add!=0){
      int x = i>=0?num1[i]:0;
      int y = j>=0?num2[j]:0;
      int res = x+y+add;
      ans.push_back(res%10+'0');
      add=res/10;
      i--;
      j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
  }
};
