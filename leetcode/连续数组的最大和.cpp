#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int maxSubArray(vector<int>&nums)
  {
    vector<int> dp((int)nums.size(),0);
    dp[0]=nums[0];
    int tem_max=nums[0];
    for(int i=1;i<(int)nums.size();i++)
    {
      dp[i]=max(dp[i-1]+nums[i],nums[i]);
      if(tem_max<dp[i]){
        tem_max=dp[i];
      }
    }
    return tem_max;
  }
};
