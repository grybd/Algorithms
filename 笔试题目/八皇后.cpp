#include <vector>
#include <string>
using namespace std;

class Solution{
private:
  vector<vector<string>> result;
  //n为输入的棋盘大小
  //row是当前递归到***的第几行了
  void backtracking(int n,int row,vector<string>&chessboard){
    if(row==n) {
      result.push_back(chessboard);
      return;
    }
    for(int col=0;col<n;col++){
      if(isValid(row,col,chessboard,n)){
        chessboard[row][col]='Q';
        backtracking(n,row+1,chessboard);
        chessboard[row][col]='.';//回溯，撤销皇后
      }
    }
  }
  bool isValid(int row,int col,vector<string>&chessboard,int n){
    //检查列
    for(int i=0;i<row;i++){
      if(chessboard[i][col]=='Q') return false;
    }
    //检查45度角是否有皇后
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
      if(chessboard[i][j]=='Q'){
        return false;
      }
    }
    //检查135度角是否有皇后
    for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
      if(chessboard[i][j]=='Q') return false;
    }
    return true;
  }
public:
  vector<vector<string>> solveNQueens(int n){
    result.clear();
    std::vector<string>chessboard(n,string(n,'.'));
    backtracking(n,0,chessboard);
    return result;
  }
};
