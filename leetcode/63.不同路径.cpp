#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    //深度搜索
    int uniquePath(int m,int n) {
        return dfs(1,1,m,n);
    }
    int dfs(int i,int j,int m,int n){
      if(i>m||j>n) return 0;
      if(i==m&&j==n) return 1;
      int right = dfs(i+1,j,m,n);
      int down = dfs(i,j+1,m,n);
      return right+down;
    }
    //动态规划
    int uniquePaths(int m,int n){
      vector<vector<int>>dp(m,vector<int>(n,0));
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
