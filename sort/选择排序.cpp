#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>&nums){
  for(int i=0;i<(int)nums.size();i++){
    int min=i;
    for(int j=i+1;j<(int)nums.size();j++){
      if(nums[j]<nums[min]){
        min = j;
      }
    }
    swap(nums[i],nums[min]);
  }
}

int main(){
  vector<int>nums = {1,9,3,4,6,7,2};
  selection_sort(nums);
  for(auto&i:nums){
    cout<< i << " ";
  }
  return 0;
}
