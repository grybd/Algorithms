#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> paths;
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(),false);
        paths.clear();
        result.clear();
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,0,0,used);
        return result;
    }
    void backtracking(vector<int>&candidates,int target,int sum,int startIndex,vector<bool>&used){
      if(sum==target){
        result.push_back(paths);
        return ;
      }
      if(sum>target) return;
      for(int i=startIndex;i<(int)candidates.size()&&sum+candidates[i]<=target;i++){
        if(i>0&&candidates[i]==candidates[i-1]&&used[i-1]==false) continue;
        sum+=candidates[i];
        used[i]=true;
        paths.push_back(candidates[i]);
        backtracking(candidates,target,sum,i+1,used);
        used[i]=false;
        sum-=candidates[i];
        paths.pop_back();
      }
    }
  };
