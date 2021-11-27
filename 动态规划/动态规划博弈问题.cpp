#include <bits/stdc++.h>
using namespace std;

int stoneGame(vector<int>piles){
  int n = piles.size();
  int dp[n][n][2];
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      dp[i][j][0]=0;
      dp[i][j][1]=0;
    }
  }
  for(int i=0;i<n;i++){
    dp[i][i][0]=piles[i];
    dp[i][i][1]=0;
  }
  for(int l=2;l<=n;l++){
    for(int i=0;i<=n-l;i++){
      int j = l+i-1;
      int left = piles[i]+dp[i+1][j][1];
      int right = piles[j]+dp[i][j-1][1];
      if(left>right){
        dp[i][j][0] = left;
        dp[i][j][1] = dp[i+1][j][0];
      }else{
        dp[i][j][0]=right;
        dp[i][j][1]=dp[i][j-1][0];
      }
    }
  }
  return dp[0][n-1][0]-dp[0][n-1][1];
}
