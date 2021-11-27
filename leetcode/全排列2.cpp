#include <vector>
#include <algorithm>
using namespace std;

class Solution{
private:
  vector<vector<int>> result;
  vector<int> path;
void DFS(vector<int>&nums,vector<bool>&used){
  if(path.size()==nums.size())
  {
    result.push_back(path);
    return;
  }

  for(int i=0;i<(int)nums.size();i++)
  {
    if(i>0&&nums[i]==nums[i-1]&&used[i-1]==false)
    {
      continue;
    }

    if(used[i]==false){

      used[i]=true;

      path.push_back(nums[i]);

      DFS(nums,used);
      path.pop_back();
      used[i]=false;
    }
  }
}

public:
  vector<vector<int>> permuteUnique(vector<int>&nums){
    result.clear();
    path.clear();
    sort(nums.begin(),nums.end());
    vector<bool> used(nums.size(),false);
    DFS(nums,used);
    return result;
  }
};
