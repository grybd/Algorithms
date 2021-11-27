#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> paths;
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates,int sum, int target) {
        backtracking(candidates,target,0,0);
        return result;
    }
    void backtracking(vector<int>&candidates,int target,int sum,int startIndex){
      if(sum==target){
        result.push_back(paths);
        return ;
      }
      if(sum>target) return;
      for(int i=startIndex;i<(int)candidates.size();i++){
        sum+=candidates[i];
        paths.push_back(candidates[i]);
        backtracking(candidates,target,sum,i);
        sum-=candidates[i];
        paths.pop_back();
      }
    }
  };
