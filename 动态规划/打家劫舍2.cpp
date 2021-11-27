#include <bits/stdc++.h>
using namespace std;

//递归解法
int dp(vector<int>&nums,int left,int right){
  if(left>right) return 0;
  int ans = max(dp(nums,left+1,right),nums[left]+dp(nums,left+2,right));
  return ans;
}
//动态规划
int dp_(vector<int>&nums,int left,int right){
  vector<int>dp(nums.size()+2,0);
  for(int i=right;i>=left;i--){
    dp[i] = max(dp[i+1],dp[i+2]+nums[i]);
  }
  return dp[left];
}
int rob(vector<int>nums){
  int n=nums.size();
  if(n==1) return nums[0];
  int left = dp_(nums,0,nums.size()-2);
  int right = dp_(nums,1,nums.size()-1);
  int res = max(left,right);
  return res;
}
