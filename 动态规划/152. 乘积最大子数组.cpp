#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution{
public:
  int maxProduct(vector<int>&nums){
      int maxval=INT_MIN,imax=1,imin=1;
      for(int i=0;i<(int)nums.size();i++){
        if(nums[i]<0){
          int tmp=imax;
          imax=imin;
          imin=tmp;
        }
        imax=max(imax*nums[i],nums[i]);
        imin=min(imin*nums[i],nums[i]);
        maxval=max(maxval,imax);
      }
    return maxval;
  }
  int maxProduct_(vector<int>&nums){
    int len=nums.size();
    if(len==0) return 0;
    // dp[i][0]：以 nums[i] 结尾的连续子数组的最小值
    // dp[i][1]：以 nums[i] 结尾的连续子数组的最大值
    vector<vector<int>>dp(len,vector<int>(2,0));
    dp[0][1]=nums[0];
    dp[0][0]= nums[0];
    for(int i=1;i<len;i++){
      if(nums[i]>=0){
        dp[i][0]=min(nums[i],nums[i]*dp[i-1][0]);
        dp[i][1]=max(nums[i],nums[i]*dp[i-1][1]);
      }else{
        dp[i][0]=min(nums[i],nums[i]*dp[i-1][1]);
        dp[i][1]=max(nums[i],nums[i]*dp[i-1][0]);
      }
    }
    int res=dp[0][1];
    for(int i=1;i<len;i++){
      res=max(res,dp[i][1]);
    }
    return res;
  }
};
