#include <vector>
#include <limits.h>
using namespace std;

class Solution{
public:
  int maxSum(int n,int m,vector<int>&nums){
    vector<vector<int>> ans;
    vector<int> res;
    int left=0,right=0;
    int sum=nums[left];
    int maxSum=INT_MIN;
    while(right<(int)nums.size())
    {
      res.push_back(nums[left]);
      right++;
      if(nums[right]>0)
      {
        sum=nums[left]+nums[right];
        res.push_back(sum)
      }
      right ++;
      maxSum=max(sum,maxSum);

    }
  }
}
