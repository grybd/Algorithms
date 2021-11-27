#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int digit_sum(int n){
      int sum = 0;
      while(n>0){
        sum+=n%10;
        n = n/10;
      }
      return sum;
    }
  private:
  int dfsSolver(int i,int j,int m,int n,int k,vector<vector<bool>>&visited){
    if(i<0||j<0||i>=m||j>=n||digit_sum(i)+digit_sum(j)>k||visited[i][j]==true){
      return 0;
    }
    visited[i][j]=true;
    int left = dfsSolver(i,j-1,m,n,k,visited);
    int right = dfsSolver(i,j+1,m,n,k,visited);
    int up = dfsSolver(i-1,j,m,n,k,visited);
    int down = dfsSolver(i+1,j,m,n,k,visited);
    return left+right+up+down+1;
  }
  public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>>visited(m,vector<bool>(n));
        int ans = dfsSolver(0,0,m,n,k,visited);
        return ans;
    }
};
