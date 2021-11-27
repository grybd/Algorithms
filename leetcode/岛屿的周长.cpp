#include <vector>
using namespace std;

class Solution{
public:
  int islandPerimeter(vector<vector<int>>&grid){
    if(grid.size()==0) return 0;
    for(int r=0;r<(int)grid.size();r++){
      for(int c=0;c<(int)grid[0].size();c++)
      {
        if(grid[r][c]==1) return dfs(grid,r,c);
      }
    }
    return 0;
  }

  int dfs(vector<vector<int>>&grid,int r,int c){
    if(!inArea(grid,r,c)) return 1;
    if(grid[r][c]==0) return 1;
    if(grid[r][c]!=1) return 0;
    grid[r][c]=2;
    return dfs(grid,r-1,c)+dfs(grid,r+1,c)+dfs(grid,r,c-1)+dfs(grid,r,c+1);
  }

  bool inArea(vector<vector<int>>&grid,int r,int c){
    return r>=0&&r<(int)grid.size()&&c>=0&&c<(int)grid[0].size();
  }
};
