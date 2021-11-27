#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
      int n=nums.size();
      if(n==0){
        return 0;
      }
      return max(myrob(nums,0,n-2),myrob(nums,1,n-1));
      }

    int myrob(vector<int>&nums,int start,int end){

      vector<int>dp(nums.size()+1,-1);

      dp[start]=nums[start],dp[start+1]=max(dp[start-1],dp[start-2]+nums[start-1]);

      for(int i=start+2;i<=end;i++)
      {
        dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
      }
      return dp[end];
    }
  };
