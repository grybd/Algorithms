#include <vector>
using namespace std;

class Solution {
public:
  //暴力解法
	int canCompleteCircuit(vector<int>&gas,vector<int>&cost){
    int n = gas.size();
    for(int i=0;i<n;i++){
      int j=i;
      int remain = gas[i];
      while(remain-gas[j]>=0){
        remain = remain-cost[j]+gas[(j+1)%n];
        j = (j+1)%n;
        if(j==i) return i;
      }
    }
    return -1;
  }
  //优化解法
  int canCompleteCircuit_(vector<int>&gas,vector<int>&cost){
    int n=gas.size();
    vector<int>farIndex(n,-1);
    vector<int>farIndexRemain(n);
    for(int i=0;i<n;i++){
      int j=i;
      int remain = gas[i];
      while(remain-cost[j]>=0){
        //到达下一个点的剩余
        remain = remain-cost[j];
        j=(j+1)%n;
        //判断之前有没有考虑过这个点
        if(farIndex[j]!=-1){
          remain = remain+farIndexRemain[j];
          j=farIndex[j];
        }else{
          //加上当前点的补给
          remain = remain+gas[j];
        }
        if(j==i) return i;
      }
      //记录当前点最远到达哪里
      farIndex[i] = j;
      farIndexRemain[i] = remain;
    }
    return -1;
  }

  int canCompleteCircuit__(vector<int>&gas,vector<int>&cost){
    int n = gas.size();
    for(int i=0;i<n;i++){
      int j=i;
      int remain = gas[i];
      while(remain-cost[j]>=0){
        remain = remain-cost[j]+gas[(j+1)%n];
        j = (j+1)%n;
        if(j==i) return i;
      }
      if(j<i) return -1;
      i=j;
    }
    return -1;
  }
};
