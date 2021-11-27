#include <vector>
#include <iostream>
using namespace std;

void test_2_wei_bag_problem1(){
  vector<int>weight={1,3,4};
  vector<int>value={15,20,30};
  int bagweight=4;
  //二维数组
  vector<vector<int>>dp(weight.size()+1,vector<int>(bagweight+1,0));
  //初始化
  for(int j=bagweight;j>=weight[0];j--){
    dp[0][j]=dp[0][j-weight[0]]+value[0];
  }
  for(int i=1;i<(int)weight.size();i++){
    for(int j=0;j<=bagweight;j++){
      if(j<weight[i]) dp[i][j]=dp[i-1][j];//不装第i个物品
      else{
        dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
      }
    }
  }
  cout<<dp[weight.size()-1][bagweight]<<endl;
}

int main(){
  test_2_wei_bag_problem1();
}
