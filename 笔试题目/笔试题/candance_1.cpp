#include <bits/stdc++.h>
using namespace std;

int Max_(vector<int>&nums,int L){
  int n=nums.size();
  int max_val=INT_MIN;
  if(L>=n) return n;
  int i=0;
  int count=1;
  while(i<n){
    int j=i+1;
    while(j<n){
      int R=nums[i]+L;
      if(nums[j]<=R){
        count++;
        j++;
        continue;
      }else{
        count=1;
        break;
      }
    }
    max_val = max(max_val,count);
    i++;
  }
  return max_val;
}
