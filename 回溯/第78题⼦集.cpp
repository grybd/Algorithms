#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
private:
    vector<int>path;
    vector<vector<int>> result;
    void backtracking(vector<int>&nums,int startIndex){
      if(path.size()>1) result.push_back(path);//不要加return，要取树上的节点

      unordered_set<int> uset;//使用set对本层元素进行去重
      for(int i=startIndex;i<(int)nums.size();i++){
        if((!path.empty()&&nums[i]<path.back())||uset.find(nums[i])!=uset.end()) continue;
        uset.insert(nums[i]);
        path.push_back(nums[i]);
        backtracking(nums,i+1);
        path.pop_back();
      }
    }
public:
    vector<vector<int>>findSubsequences(vector<int>&nums) {
      result.clear();
      path.clear();
      backtracking(nums,0);
      return result;
    }
};
