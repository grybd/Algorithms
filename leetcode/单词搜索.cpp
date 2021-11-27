#include <vector>
#include <string>
using namespace std;
class Solution{
public:
//  int dir[4][4]={{-1,0},{1,0},{0,-1},{0,1}};
  bool exist(vector<vector<char>>&board,string word){
    int n=board.size();
    int m=board[0].size();

    vector<vector<char>>used(n,vector<char>(m));
    //vector<vector<int> >swp(n,vector<int>(m));//定义二维数组swp[][]，n行 m列
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        //遍历找起点，作为递归入口
        if(board[i][j]==word[0]&&canFind(i,j,0,word,board,used))
        {
          return true;
        }
      }
    }
    return false;
  }

  bool canFind(int raw,int col,int index,string &word,vector<vector<char>>&board,vector<vector<char>>&used)
  {
    if(index==(int)word.length()) return true;
    if(raw<0||raw>=(int)board.size()||col<0||col>=(int)board[0].size()) return false;
    if(used[raw][col]||board[raw][col]!=word[index]) return false;
    used[raw][col]=true;
    bool canfindRes=canFind(raw+1,col,index+1,word,board,used)||canFind(raw-1,col,index+1,word,board,used)\
    ||canFind(raw,col+1,index+1,word,board,used)||canFind(raw,col-1,index+1,word,board,used);

    if(canfindRes) return true;
    used[raw][col]=false;
    return false;
    }
};
