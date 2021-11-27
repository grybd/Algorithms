#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  void nextPermutation(vector<int>&nums){
    int i=0;
    for(int i=nums.size()-2;i>=0;--i){
      if(nums[i]<nums[i+1]) break;
    }
    if(i==-1) reverse(nums.begin(),nums.end());
    else{
      for(int j=nums.size()-1;j>=i+1;--j){
        if(nums[i]<nums[j]){
          swap(nums[i],nums[j]);
          reverse(nums.begin()+i+1,nums.end());
          break;
        }
      }
    }
  }
};
