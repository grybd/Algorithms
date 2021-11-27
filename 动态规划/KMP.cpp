#include <bits/stdc++.h>
using namespace std;

class KMP{
private:
  vector<vector<int>>dp;
  string pat;
public:
  void  kmp(string pat){
    int m = pat.size();
    vector<vector<int>>dp(m,vector<int>(256,0));
    dp[0][pat[0]]=1;
    int X = 0;
    for(int j=0;j<m;j++){
      for(int c=0;c<256;c++){
        dp[j][c]=dp[X][c];
      }
      dp[j][pat[j]] = j+1;
      X = dp[X][pat[j]];
    }
  }
int search(string txt){
  int m=pat.size();
  int n = txt.size();
  int j=0;
  for(int i=0;i<n;i++){
    j = dp[j][txt[i]];
    if(j==m) return i-m+1;
  }
}

};
