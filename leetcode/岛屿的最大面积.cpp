#include <vector>
using namespace std;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
        for(int r=0;r<(int)grid.size();r++)
        {
          for(int c=0;c<(int)grid[0].size();c++)
          {
            if(grid[r][c]==1){
              int a=area(grid,r,c);
              res=max(res,a);
            }
          }
        }
        return res;
    }

    int area(vector<vector<int>>&grid,int r,int c)
    {
      if(!inArea(grid,r,c)) return 0;
      if(grid[r][c]!=1) return 0;
      grid[r][c]=2;
      return 1+area(grid,r-1,c)+area(grid,r+1,c)+area(grid,r,c-1)+area(grid,r,c+1);
    }

    bool inArea(vector<vector<int>>&grid,int r, int c){
      return r>=0&&r<(int)grid.size()&&c>=0&&c<(int)grid[0].size();
    }
};
