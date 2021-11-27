#include <iostream>
#include <vector>
using namespace std;

class Solution{
  public:
    vector<vector<int>>combine(int n,int k){
      result.clear();
      path.clear();
      backtracking(n,k,1);
      return result;
    }
  private:
    vector<int> path;//保存符合要求的结果集合
    vector<vector<int>> result;
    void backtracking(int n,int k,int index){
      if((int)path.size()==k){
        result.push_back(path);
        return;
      }
      for(int i=index;i<=n;i++){
        path.push_back(i);
        backtracking(n,k,i+1);
        path.pop_back();
      }
    }
};
