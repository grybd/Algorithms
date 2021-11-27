#include <vector>
using namespace std;
class Solution{
public:
  vector<int>path;
  vector<vector<int>>result;
  vector<vector<int>>permute(vector<int>&nums){
    result.clear();
    path.clear();
    vector<bool>used(nums.size(),false);
    backtracking(nums,used);
    return result;
  }
  void backtracking(vector<int>&nums,vector<bool>&used){
    if(path.size()==nums.size()){
      result.push_back(path);
      return ;
    }
    for(int i=0;i<(int)nums.size();i++){
      if(used[i]==true) continue;
      used[i] = true;
      path.push_back(nums[i]);
      backtracking(nums,used);
      path.pop_back();
      used[i]=false;
    }
  }
 };
