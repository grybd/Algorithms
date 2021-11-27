#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
  private:
    vector<vector<string>>result;
    void backtracking(int n,int row,vector<string>&chessboard){
      if(row==n) {
        result.push_back(chessboard);
        return;
      }
      for(int col=0;col<n;col++){
        if(isValid(row,col,chessboard,n)){
          chessboard[row][col]='Q';
          backtracking(n,row+1,chessboard);
          chessboard[row][col]='.';
        }
      }
      }
    bool isValid(int row,int col,vector<string>&chessboard,int n){
      //判断列
      for(int i=0;i<row;i++){
        if(chessboard[i][col]=='Q') return false;
      }
      //判断45度角
      for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
        if(chessboard[i][j]=='Q') return false;
      }
      //判断135度角
      for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
        if(chessboard[i][j]=='Q') return false;
      }
      return true;
    }
  public:
    vector<vector<string>> solveNQueens(int n) {
      result.clear();
      vector<string>chessboard(n,string(n,'.'));
      backtracking(n,0,chessboard);
      int t=result.size();
      int i=0;
      cout<<"[";
      while(i<t){
        cout<<"[";
        for(int k=0;k<n;k++){
          cout<<result[i][k]<<",";
        }
        cout<<"]";
        i++;
      }
      cout<<"]";
      return result;
    }
};
int main(){
  Solution s;
  int n;
  cin>>n;
  s.solveNQueens(n);
}
