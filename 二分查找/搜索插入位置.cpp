#include <vector>
using namespace std;

class Solution{
public:
  int searchInsert(vector<int>&nums,int target){
    int n=nums.size();
    int left=0;
    int right=n-1;//定义target在左闭右闭的区间里，[left,right]

    while(left<=right){//当left==right，区间[left,right]依然有效
      int middle=left+((right-left)/2);
      if(nums[middle]>target){
        right=middle-1;//target在左区间
      }else if(nums[middle]<target){
        left=middle+1;//target在右区间，所以[middle+1,right]
      }
      else{
        return middle;
      }
    }
    return right+1;
  }

  int _searchInsert(vector<int>&nums,int target){
    int n=nums.size();
    int left=0;
    int right=n;//定义target在左闭右闭的区间里，[left,right)

    while(left<right){//当left==right，在区间[left,right)是无效的区间
      int middle=left+((right-left)/2);
      if(nums[middle]>target){
        right=middle;//target在左区间
      }else if(nums[middle]<target){
        left=middle+1;//target在右区间，所以[middle+1,right)
      }
      else{
        return middle;
      }
    }
    return right;
  }

};
