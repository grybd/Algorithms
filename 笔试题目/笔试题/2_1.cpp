#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
  int count;
  vector<int>path;
  vector<vector<int>>ans;
  vector<vector<vector<int>>> res;
  bool isDc_(vector<vector<int>>matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        if(matrix[i][j]!=matrix[j][i]) return false;
      }
    }
    return true;
  }
  vector<vector<vector<int>>> P_K_(vector<vector<int>>&matrix,int k){
      int n=matrix.size(),m=matrix[0].size();
      backtracking(matrix,n,m,count,k);
      return res;
  }
  //
  vector<vector<int>> ZD_X(vector<vector<vector<int>>>&nums){
      for(auto s:nums){
        comZ()
      }
  }
  backtracking(vector<vector<int>>maxtrix,int n,int m,int count,int k){
    if(k==count){
      res.push_back(ans);
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        maxtrix[i][j]=0;
        count++;
        path.push_back(maxtrix[i][j]);
        if((int)path.size()==n){
          ans.push_back(path);
        }
        backtracking(maxtrix,n,m,count,k);
        path.pop_back();
        ans.pop_back();
        count--;
      }
    }
  }
};
