#include <bits/stdc++.h>
using namespace std;

void quicksort(vector<int>&nums,int left,int right){
  if(left>right) return;
  int i=left,j=right,temp = nums[right];
  while(i!=j){
    while(i<j&&nums[i]<temp) i++;
    while(i<j&&nums[j]>temp) j--;
    if(i<j){
      swap(nums[i],nums[j]);
    }
  }
  swap(nums[i],nums[right]);
  quicksort(nums,left,i-1);
  quicksort(nums,i+1,right);
}

int main(){
  vector<int>ans={3,4,2,1,6,7,8};
  quicksort(ans,0,ans.size());
  for(auto i:ans){
     cout<< i << " ";
  }
  return 0;
}
