#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int>path;
    vector<vector<int>> result;
    void backtracking(int k,int n,int sum,int startIndex){
      if((int)path.size()==k){
        if(sum==n){
          result.push_back(path);
          return ;
        }
      }
      for(int i=startIndex;i<=9;i++){
        path.push_back(i);
        sum+=i;
        backtracking(k,n,sum,i+1);
        sum-=i;
        path.pop_back();
      }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
      backtracking(k,n,0,1);
      return result;
    }
};
