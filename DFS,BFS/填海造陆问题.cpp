#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool inArea(vector<vector<int>>&grid,int row,int col){
      return row>=0&&col>=0&&row<(int)grid.size()&&col<(int)grid[0].size();
    }
    int dfs(vector<vector<int>>&grid,int row,int col,int index){
      if(!inArea(grid,row,col)) return 0;
      if(grid[row][col]!=1) return 0;
      grid[row][col]=index;
      return 1+dfs(grid,row+1,col,index)+dfs(grid,row-1,col,index)+dfs(grid,row,col+1,index)+dfs(grid,row,col-1,index);
    }
    set<int>findNeighbour(vector<vector<int>>&grid,int row,int col){
      set<int>hashset;
      if(inArea(grid,row+1,col)&&grid[row+1][col]!=0){
        hashset.insert(grid[row+1][col]);
      }
      if(inArea(grid,row-1,col)&&grid[row-1][col]!=0){
        hashset.insert(grid[row-1][col]);
      }
      if(inArea(grid,row,col+1)&&grid[row][col+1]!=0){
        hashset.insert(grid[row][col+1]);
      }
      if(inArea(grid,row,col-1)&&grid[row][col-1]!=0){
        hashset.insert(grid[row][col-1]);
      }
      return hashset;
    }
    int largestIsland(vector<vector<int>>&grid){
        int row=grid.size();
        int col=grid[0].size();
        int index = 2;
        int max_area=0;
        if(row==0&&col==0){
          return 1;
        }
        unordered_map<int,int>record;
        for(int i=0;i<row;i++){
          for(int j=0;j<col;j++){
            if(grid[i][j]==1){
              int size=dfs(grid,i,j,index);
              record[index]=size;
              max_area=max(max_area,size);
              index++;
            }
          }
        }
        if(max_area==0){
          return 1;
        }
        for(int i=0;i<row;i++){
          for(int j=0;j<col;j++){
            if(grid[i][j]==0){
              set<int>neighbors=findNeighbour(grid,i,j);
              if(neighbors.size()<1){
                continue;
              }
              int area = 1;
              for(auto it=neighbors.begin();it!=neighbors.end();it++){
                area+=record[*it];
              }
              max_area=max(max_area,area);
            }
          }
        }
        return max_area;
    }
};
