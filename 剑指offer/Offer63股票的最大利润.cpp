#include <vector>
#include <limits.h>
using namespace std;

class Solution{
public:
  //暴力解法
	int maxProfit_(vector<int>&prices){
    int result=0;
    for(int i=0;i<(int)prices.size();i++){
      for(int j=i+1;j<(int)prices.size();j++){
        result = max(result,prices[j]-prices[i]);
      }
    }
    return result;
  }
  //贪心算法
  int maxProfit__(vector<int>&prices){
    int low = INT_MAX;
    int result = 0;
    for(int i=0;i<(int)prices.size();i++){
      low = min(low,prices[i]);
      result = max(result,prices[i]-low);
    }
    return result;
  }
  //动态规划
  int maxProfit(vector<int>&prices){
    int len=prices.size();
    if(len==0) return 0;
    vector<vector<int>>dp(len,vector<int>(2,0));
    dp[0][0]=-prices[0];
    dp[0][1]=0;
    for(int i=1;i<len;i++){
      dp[i][0]=max(dp[i-1][0],-prices[i]);
      dp[i][1]=max(dp[i-1][1],prices[i]+dp[i-1][0]);
    }
    return dp[len-1][1];
  }
};
