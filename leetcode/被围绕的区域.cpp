#include <vector>
using namespace std;

class Solution{
public:
  void solve(vector<vector<char>>&board) {
    //判断边界情况
    if(board.size()==0) return;
    int m = board.size();
    int n = board[0].size();

    for(int i=0; i<m; i++)
    {
      for(int j=0;j<n;j++)
      {
        bool isEdge=i==0||j==0||i==m-1||j==n-1;
        if(isEdge&&board[i][j]=='O'){
          dfs(board,i,j);
        }
      }
    }


  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(board[i][j]=='O'){
        board[i][j]='X';
      }
      if(board[i][j]=='@')
      {
        board[i][j]='O';
      }
    }
  }
}

 void dfs(vector<vector<char>>&board,int i,int j)
 {
    if(i<0||j<0||i>=(int)board.size()||j>=(int)board[0].size()||board[i][j]=='@'||board[i][j]=='X') return;
    board[i][j]='@';

    dfs(board,i-1,j);
    dfs(board,i+1,j);
    dfs(board,i,j-1);
    dfs(board,i,j+1);
 }
};
