#include <bits/stdc++.h>
using namespace std;


  vector<vector<int>>threeSum(vector<int>&nums){
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<(int)nums.size();i++){
      if(nums[0]>0) return ans;
      if(i>0&&nums[i-1]==nums[i]) continue;
      int left = i+1,right = nums.size()-1;
      while(left<right){
        if(left<right&&nums[left]+nums[right]==-nums[i]){
          ans.push_back({nums[i],nums[left],nums[right]});
          left++;
          right--;
          while(left<right&&nums[left-1]==nums[left]) left++;
          while(left<right&&nums[right+1]==nums[right]) right--;
        }else if(nums[left]+nums[right]<-nums[i]){
          left++;
        }else{
          right--;
        }
      }
    }
    return ans;
  }

  int main(){
    vector<int> nums = {-1,1,0,2,-2,0,11,-11,0};
    vector<vector<int>>ans = threeSum(nums);
    for(auto a:ans){
      for(auto i:a){
        cout<< i << " ";
      }
      cout<<endl;
    }
    return 0;
  }
