#include <bits/stdc++.h>
using namespace std;

int min_val=INT_MIN;
int dfs(vector<vector<int>>&grid,int i,int j,int start,int end,vector<int>&used){
  if(i<0||i>=grid.size()||j<0||j>=grid[0].size()) return 0;
  if(i==start&&j==end) return min_val;
  if(used[i][j]){
    return 0;
  }
  used[i][j]=true;
  if(grid[i][j]>grid[i-1][j]||grid[i+1][j]||grid[i][j-1]||grid[i][j+1]){
    dfs(grid,i-1,j,start,end,used);
    used[i][j] = false;
    dfs(grid,i+1,j,start,end,used);
    use[i][j] = false;
    dfs(grid,i,j-1,start,end,used);
    use[i][j] = false;
    dfs(grid,i,j+1,start,end,used);
    use[i][j] = false;
  }else{
    if(grid[i-1][j]>grid[i][j]){
      min_val
    }
  }

}
