#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<vector<string>>res;
  vector<vector<string>> solveNqueens(int n){
    vector<string> board(n,string(n,'.'));
    backtrack(board,0);
    return res;
  }

  void backtrack(vector<string>&board,int row){

    if(row==(int)board.size())
    {
      res.push_back(board);
      return ;
    }

    for(int col=0;col<(int)board.size();col++)
    {
      if(!isValid(board,row,col)) continue;
      board[row][col]='Q';
      backtrack(board,row+1);
      board[row][col]='.';
    }
  }

  bool isValid(vector<string>&board,int &row,int &col)
  {
    //检查列是否有皇后冲突
    for(int i=0;i<(int)board.size();i++)
    {
      if(board[i][col]=='Q') return false;
    }
    //检查左上方有没有皇后冲突
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
    {
      if(board[i][j]=='Q') return false;
    }
    //检查右上方是否有皇后冲突
    for(int i=row-1,j=col+1;i>=0&&j<board.size();i--,j++)
    {
      if(board[i][j]=='Q') return false;
    }
    return true;
  }
};
