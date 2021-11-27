#include <vector>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(int targetSum,int k,int Sum,int index){
      if((int)path.size()==k){
        if(targetSum==Sum) result.push_back(path);
        return;
      }
      for(int i=index;i<=9;i++){
        Sum+=i;
        path.push_back(i);
        backtracking(targetSum,k,Sum,i+1);
        path.pop_back();
        Sum-=i;
      }
    }
public:
	vector<vector<int>> combinationSum(int k,int n){
    path.clear();
    result.clear();
    backtracking(n,k,0,1);
    return result;
  }
};
