#include <bits/stdc++.h>
using namespace std;

//递归解法
int dp(vector<int>&nums,int start){
  if(start>=(int)nums.size()){
    return 0;
  }
  int res = max(dp(nums,start+1),nums[start]+dp(nums,start+2));
  return res;
}
int rob(vector<int>&nums){
  vector<int>mem(nums.size()+2,-1);
  return dp(nums,0);
}
//备忘录递归
int dp(vector<int>&nums,int start,vector<int>&mems){
  if(start>=(int)nums.size()){
    return 0;
  }
  if(mems[start]!=-1) return mems[start];
  int res = max(dp(nums,start+1),nums[start]+dp(nums,start+2));
  mems[start] = res;
  return res;
}
int rob_(vector<int>&nums){
  vector<int>mems(nums.size()+2,-1);
  return dp(nums,0,mems);
}
//动态规划
int rob__(vector<int>&nums){
  vector<int>dp(nums.size()+2,0);
  for(int i=nums.size()-1;i>=0;i--){
    dp[i] = max(dp[i+1],dp[i+2]+nums[i]);
  }
  return dp[0];
}
