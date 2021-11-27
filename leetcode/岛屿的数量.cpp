#include <vector>
using namespace std;

class Solution{
public:
  int numIsland(vector<vector<int>>&grid)
  {
    int count=0;
    if(grid.size()==0) return 0;
    int n=grid.size();
    int m=grid[0].size();
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        if(grid[i][j]=='1')
        {
          dfs(grid,i,j);
          count++;
        }
      }
    }
  }

  void dfs(vector<vector<int>>&grid,int i,int j)
  {
    if(i<0||i>=(int)grid.size()||j<0||j>=(int)grid[0].size()||grid[i][j]=='0')
    return;

    grid[i][j]='0';

    dfs(grid,i-1,j);
    dfs(grid,i+1,j);
    dfs(grid,i,j-1);
    dfs(grid,i,j+1);
  }
};
