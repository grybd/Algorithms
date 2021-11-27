#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1) return 0;

        int dp[n][2];

        dp[0][0]=0,dp[0][1]=-prices[0],dp[1][0]=max(0,prices[1]-prices[0]),\
        dp[1][1]=max(-prices[0],-prices[1]);

        for(int i=2;i<n;i++)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-2][0]-prices[i]);
        }

        return dp[n-1][0];

    }
};
