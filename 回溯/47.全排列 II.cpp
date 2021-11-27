#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
private:
  vector<int> path;
  vector<vector<int>> result;
  void backtracking(vector<int>&nums,vector<bool>&used){
    if(path.size()==nums.size()){
      result.push_back(path);
      return;
    }
    for(int i=0;i<(int)nums.size();i++){
      if(used[i]==true) continue;
      if(i>0&&nums[i]==nums[i-1]&&used[i-1]==false) continue;
      used[i]=true;
      path.push_back(nums[i]);
      backtracking(nums,used);
      path.pop_back();
      used[i]=false;
    }
  }
public:
    vector<vector<int>> permute(vector<int>& nums) {
      result.clear();
      path.clear();
      sort(nums.begin(),nums.end());
      vector<bool>used(nums.size(),false);
      backtracking(nums,used);
      return result;
    }
};
