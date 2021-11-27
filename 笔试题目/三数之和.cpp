#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>>threeSum(vector<int>&nums){
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0; i<(int)nums.size();i++){
          if(nums[i]>0) break;
          if(i>0&&nums[i]==nums[i-1]) continue;
          int left = i+1,right = nums.size()-1;
          int target = -nums[i];
          while(left<right){
                if(nums[left]+nums[right]==target){
                ans.push_back({nums[i],nums[left],nums[right]});
                left++;right--;
                while(left<right&&nums[left]==nums[left-1]) left++;
                while(left<right&&nums[right+1]==nums[right]) right--;
              }else if(nums[left]+nums[right]<target) left++;
               else{
                right--;
              }
            }
          }
          return ans;
        }
      };
