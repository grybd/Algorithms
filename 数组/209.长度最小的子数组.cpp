#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
  //暴力解法；
    int minSubArrayLen(int target, vector<int>& nums) {
      int result=INT_MAX;
      int sum=0;
      int subLength=0;
      for(int i=0;i<(int)nums.size();i++){
        sum=0;
        for(int j=i;j<(int)nums.size();j++){
          sum+=nums[j];
          if(sum>=target){
            subLength=j-i+1;
            result=result<subLength?result:subLength;
            break;
          }
        }
      }
      return result==INT_MAX?0:result;
    }
    int _minSubArrayLen(int target, vector<int>& nums){
      int result=INT_MAX;
      int sum=0;
      int subLength=0;
      int i=0;
      for(int j=0;j<(int)nums.size();j++){
        sum+=nums[j];
        while(sum>=target)
        {
          subLength=j-i+1;
          result=min(subLength,result);
          sum-=nums[i++];
        }
      }
      return result=result==INT_MAX?0:result;
    }
};
