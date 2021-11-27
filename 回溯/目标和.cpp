#include <bits/stdc++.h>
using namespace std;

int result = 0;
void backtrack(vector<int>&num, int ,int);
int findTargetSumWay(vector<int>&nums,int target){
  if(nums.size()==0) return 0;
  backtrack(nums,0,target);
  return result;
}
//回溯法
void backtrack(vector<int>&nums,int i,int rest){
  if(i==(int)nums.size()){
    if(rest==0){
      result++;
    }
    return ;
  }
  rest += nums[i];
  backtrack(nums,i+1,rest);
  rest-=nums[i];
  rest -=nums[i];
  backtrack(nums,i+1,rest);
  rest+=nums[i];
}
