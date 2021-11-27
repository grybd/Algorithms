#include <vector>
using namespace std;
//dp[i] 表⽰以nums[i]这个数结尾的最⻓递增⼦序列
//的⻓度
int lengthofLIS(vector<int>&nums){
  vector<int>dp(nums.size(),1);
  for(int i=0;i<(int)nums.size();i++){
    for(int j=0;j<i;j++){
      if(nums[i]>nums[j]){
        dp[i] = max(dp[i],dp[j]+1);
      }
    }
  }
  int res=0;
  for(int i=0;i<(int)dp.size();i++){
    res = max(res,dp[i]);
  }
  return res;
}
