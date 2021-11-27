#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>&Coins,int amount){
  vector<int>dp(amount+1,amount+1);
  //base case
  dp[0] = 0;
  for(int i=0;i<amount+1;i++){
    for(int coin:Coins){
      if(i-coin<0) continue;
      dp[i] = min(dp[i],1+dp[i-coin]);
    }
  }
  return (dp[amount]==amount+1)?-1:dp[amount];
}
