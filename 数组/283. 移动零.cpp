#include <vector>
using namespace std;

class Solution{
public:
  void moveZeroes(vector<int>&nums){
    if(nums.size()==0) return;
    //第一次遍历的时候，j指针记录非0的个数，只要是非0的统统都赋给nums[j]
    int j=0;
    for(int i=0;i<(int)nums.size();i++){
      if(nums[i]!=0)
      {
        nums[j++]=nums[i];
      }
    }
    for(int i=j;i<(int)nums.size();i++){
      nums[i]=0;
    }
  }
  void _moveZeroes(vector<int>&nums){
    if(nums.size()==0) return;
    int j=0;
    for(int i=0;i<(int)nums.size();i++){
      if(nums[i]!=0){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j++]=temp;
      }
    }
  }
};
