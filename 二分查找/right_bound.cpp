#include <bits/stdc++.h>
using namespace std;

int right_bound(vector<int>&nums,int target){
    if(nums.size()==0) return -1;
    int left = 0,right = nums.size();
    while(left<right){
      int mid = left+(right-left)/2;
      if(nums[mid]==target){
        left = mid+1;
      }else if(nums[mid]<target){
        left = mid+1;
      }else if(nums[mid]>target){
        right = mid;
      }
    }
    return left-1;
}
