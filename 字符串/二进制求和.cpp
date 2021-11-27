#include <bits/stdc++.h>
using namespace std;

class Solution{
   public:
   string addBinary(string a,string b){
     int n=a.size()-1;
     int m=b.size()-1;
     int add=0;
     string ans;
     while(n>=0||m>=0||add!=0){
       int x = n>=0?a[n]-'0':0;
       int y = m>=0?b[m]-'0':0;
       int sum = x+y+add;
       ans.push_back(sum%2+'0');
       add = sum/2;
       n--;
       m--;
     }
    reverse(ans.begin(),ans.end());
     return ans;
   }
};
