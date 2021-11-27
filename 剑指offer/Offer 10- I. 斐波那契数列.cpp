#include <vector>
using namespace std;

class Solution {
public:
  int fib_(int n){
    return dfs_(n);
  }
  int dfs_(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    int leftFib = dfs_(n-1);
    int rightFib = dfs_(n-2);
    return (leftFib+rightFib)%1000000007;
  }
  int _fib_(int n){
    vector<int> mem(n+1,-1);
    return _dfs_(n,mem);
  }
  int _dfs_(int n,vector<int>&mem){
    if(n==0) return 0;
    if(n==1) return 1;
    if(mem[n]!=-1) return mem[n];
    int leftFib = _dfs_(n-1,mem);
    int rightFib = _dfs_(n-2,mem);
    mem[n]=(leftFib+rightFib)%1000000007;
    return mem[n];
  }
  //动态规划
  int fib__(int n){
    if(n<=1) return n;
    vector<int>dp(n+1,0);
    dp[0]=1,dp[1]=1;
    for(int i=2;i<=n;i++){
      dp[i] = dp[i-1] + dp[i-2];
      dp[i]%=1000000007;
    }
    return dp[n];
  }
  //空间压缩法
  int fib(int n){
    if(n<=1) return n;
    int prev = 0;
    int curr = 1;
    for(int i=2;i<=n;i++){
      int sum = (prev+curr)%1000000007;
      prev = curr;
      curr = sum;
    }
    return curr;
  }
};
