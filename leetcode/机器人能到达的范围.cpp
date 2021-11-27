#include <vector>
using namespace std;

class Solution{
public:
  int movingCount(int m,int n,int k)
  {
     vector<vector<bool>> vb(m,vector<bool>(n));
     return dfs(0,0,m,n,k,vb);
  }

  int dfs(int i,int j,int m,int n,int k,vector<vector<bool>>&vb){
    if(i<0||i>=m||j<0||j>=n||k<sum(i,j)||vb[i][j]) return 0;
    vb[i][j]=true;
    return 1+dfs(i-1,j,m,n,k,vb)+dfs(i+1,j,m,n,k,vb)+dfs(i,j-1,m,n,k,vb)+dfs(i,j+1,m,n,k,vb);
  }

  int sum(int i, int j){
    int sum=0;
    while(i!=0){
      sum+=i%10;
      i/=10;
    }
    while(j!=0){
      sum+=j%10;
      j/=10;
    }
    return sum;
  }
};
