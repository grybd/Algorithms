#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&grid,int i,int j,vector<vector<bool>>&visited){
  int m=grid.size(),n=grid[0].size();
  if(i<0||j<0||i>=m||j>=n){
    return;
  }
  if(visited[i][j]){
    return;
  }
  visited[i][j]=true;
  dfs(grid,i-1,j);
  dfs(grid,i+1,j);
  dfs(grid,i,j-1);
  dfs(grid,i,j+1);
  visited[i][j]=false;
}
