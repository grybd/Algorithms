#include <bits/stdc++.h>
using namespace std;

void seletion_sort(vector<int>&nums){
  for(int i=0;i<(int)nums.size()-1;i++){
     int min = i;
     for(int j=i+1;j<(int)nums.size();j++){
        if(nums[j]<nums[min]){
          min = j;
        }
     }
     swap(nums[i],nums[min]);
  }
}
