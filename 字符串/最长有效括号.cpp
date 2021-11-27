#include <stack>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
    //暴力解法
    stack<char>sta;
    bool isVaild(string s){
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                sta.push('(');
            }
            else if(!sta.empty()&&sta.top()=='('){
                sta.pop();
            }
            else{
                return false;
            }
        }
        return sta.empty();
    }

    int longestValidParentheses(string s){
        int maxLen = 0;
        for(int i=0;i<s.length();i++){
            for(int j=i+2;j<=s.length();j+=2){
                if(isVaild(s.substr(i,j-i))){
                    maxLen=max(maxLen,j-i);
                }
            }
        }
        return maxLen;
    }
    //动态规划
    int longestValidParentheses(string s){
        int size=s.length();
        vector<int>dp(size,0);
        int maxVal=0;
        for(int i=1;i<size;i++){
            if(s[i]==')'){
                if(s[i-1]=='('){
                    dp[i]=(i>=2?dp[i-2]:0)+2;
                }else if(i-dp[i-1]>0&&s[i-dp[i-dp[i-1]-1]]='('){
                    dp[i]=dp[i-1]+((i-dp[i-1])>=2?dp[i-dp[i-dp[i-1]-2]:0)+2;
                }
            }
            maxVal=max(maxVal,dp[i]);
        }
        return maxVal;
    }
};