#include <vector>
#include <algorithm>
using namespace std;
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  vector<vector<int>> fourSum(vector<int>&nums,int target){
    vector<vector<int>>result;
    sort(nums.begin(),nums.end());
    for(int k=0;k<(int)nums.size();k++){
      if(k>0&&nums[k]==nums[k-1]) continue;
      for(int i=k+1;i<(int)nums.size();i++){
        if(i>k+1&&nums[i]==nums[i-1]) continue;
        int left=i+1;
        int right=nums.size()-1;
        while(left<right){
          if(long(nums[k])+long(nums[i])+long(nums[left])+long(nums[right])>target) right--;
          else if(long(nums[k])+long(nums[i])+long(nums[left])+long(nums[right])<target) left++;
          else{
            result.push_back(vector<int>{nums[k],nums[i],nums[left],nums[right]});
            while(left<right&&nums[right]==nums[right-1]) right--;
            while(left<right&&nums[left]==nums[left+1]) left++;
            right--;
            left++;
          }
        }
      }
    }
    return result;
  }
};
