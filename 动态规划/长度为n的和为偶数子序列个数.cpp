#include <bits/stdc++.h>
using namespace std;

/*
*dp[i][j][0]截至到第i个字符，长度为j+1的子序列和为偶数个数
*dp[i][j][1]截至到第i个字符，长度为j+1的子序列和为奇数个数
*/

class Solution{
public:
  static int sumArray(vector<int>&nums,int k){
    int n=nums.size();
    if(nums.size()==0) return 0;
    int dp[n][k][2];
    dp[0][0][0]=nums[0]%2==0?1:0;
    dp[0][0][1]=nums[0]%2==0?0:1;

    for(int i=1;i<n;i++){
      if(nums[i]%2==0){
        dp[i][0][0]=dp[i-1][0][0]+1;
        dp[i][0][1]=dp[i-1][0][1];
      }else{
        dp[i][0][0]=dp[i-1][0][0];
        dp[i][0][1]=dp[i-1][0][1]+1;
      }
    }
    for(int i=1;i<n;i++){
      for(int j=1;j<k;j++){
        if(nums[i]%2==0){
          dp[i][j][0]=dp[i-1][j-1][0]+dp[i-1][j][0];
          dp[i][j][1]=dp[i-1][j][1]+dp[i-1][j-1][1];
        }else{
          dp[i][j][0]=dp[i-1][j-1][1]+dp[i-1][j][0];
          dp[i][j][1]=dp[i-1][j][1]+dp[i-1][j-1][0];
        }
      }
    }
    return dp[n-1][k-1][0];
  }
};
