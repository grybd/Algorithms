#include <bits/stdc++.h>
using namespace std;
bool findV_(vector<int>&nums,int k){
  int n=nums.size();
  if(n%k) return false;
  if(n==1) return true;
  sort(nums.begin(),nums.end());
  int i=0,j=1;
  int count=1;
  while(i<n){
    int m = i;
    while(m<k*count){
      if(j<n&&abs(nums[j]-nums[m])>1) return false;
      m++;
      j++;
    }
    count++;
    i+=k;
  }
  return true;
}
