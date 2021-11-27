#include<bits/stdc++.h>
using namespace std;

void quicksort(vector<int>&nums,int left,int right){
  if(left>right) return ;
  int i=left,j = right,temp = nums[right];
  while(i!=j){
    while(i<j&&nums[i]<=temp) i++;
    while(i<j&&nums[j]>=temp) j--;
    if(i<j){
      swap(nums[i],nums[j]);
    }
  }
  swap(nums[right],nums[i]);
  quicksort(nums,left,i-1);
  quicksort(nums,i+1,right);
}

int main(){
  vector<int> nums = {9,8,5,4,3,2,1};
  int n = nums.size()-1;
  quicksort(nums,0,n);
  for(auto i:nums){
    cout<< i << " ";
  }
  return 0;
}
