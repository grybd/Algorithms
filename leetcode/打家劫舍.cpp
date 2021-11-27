#include <vector>
#include <string>
using namespace std;
/*
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>memo(nums.size(),-1);
        return dp(nums,0,memo);
    }

    int dp(vector<int>&nums,int start,vector<int>&memo){
        if(start>=(int)nums.size()) return 0;
        if(memo[start]!=-1) return memo[start];
        int res=max(dp(nums,start+1,memo),nums[start]+dp(nums,start+2,memo));
        memo[start]=res;
        return res;
    }
};
*/

//自底向上的动态规划解法
class Solution {
public:
    int rob(vector<int>& nums) {

      if(nums.size()==0){
        return 0;
      }

      int n=nums.size();
      vector<int>dp(n+1,-1);
      dp[0]=0,dp[1]=nums[0];

      for(int i=2;i<=n;i++)
      {
        dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
      }
      return dp[n];
    }
  };
