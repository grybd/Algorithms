#include <vector>
#include <iostream>
using namespace std;

class Solution {
    private:
       //递归解法
       int dfs(int i,int j, int m,int n){
           if(i>m||j>n) return 0;//越界了
           if(i==m&&j==n) return 1;//找到一种方法，相当于找到了叶子节点
           return dfs(i+1,j,m,n)+dfs(i,j+1,m,n);
       }

       public:
          int uniquePath_(int m,int n){
              return dfs(1,1,m,n);
          }
        //动态规划
        int uniquePaths(int m,int n){
            vector<vector<int>> dp(m,vector<int>(n,0));
            for(int i=0;i<m;i++) dp[i][0]=1;
            for(int j=0;j<n;j++) dp[0][j]=1;
            for(int i=1;i<m;i++){
                for(int j=1;j<n;j++){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
            return dp[m-1][n-1];
        }
};