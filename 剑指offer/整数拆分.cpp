#include <limits.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int integerBreak_(int n){
    if(n==2) return 1;
    int res = -1;
    for(int i=1;i<=n-1;i++){
      res=max(res,max(i*(n-i),i*integerBreak_(n-i)));
    }
    return res;
  }
  int integerBreak(int n){
    vector<int>dp(n+1);
    for(int i=2;i<=n;i++){
      int curMax=0;
      for(int j=1;j<i;j++){
        curMax=max(curMax,max(j*(i-j),j*dp[i-j]));
      }
      dp[i]=curMax;
    }
    return dp[n];
  }
};
