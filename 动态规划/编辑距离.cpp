#include <vector>
#include <string>
using namespace std;

int minDistance(string s1,string s2){
  int m = s1.size();
  int n = s2.size();
  vector<vector<int>>dp(m,vector<int>(n,0));
  //base case;
  for (int i = 1; i<=m;i++){
    dp[i][0] = i;
  }
  for (int j=0; j<=n; j++){
    dp[0][j] = j;
  }
  for(int i=1; i<=m;i++){
    for(int j=1; j<=n;j++){
      if(s1[i-1]==s2[j-1]){
         dp[i][j] = dp[i-1][j-1];
      }else{
        dp[i][j] = dp[i-1][j] + 1;//插入
        dp[i][j] = dp[i][j-1] + 1;//删除
        dp[i][j] = dp[i-1][j-1] + 1;//替换
      }
    }
  }
  return dp[m][n];
}
