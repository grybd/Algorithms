#include<bits/stdc++.h>
using namespace std;
int sum=0;
int dfs(vector<int>&nums,int left,int right){
  if(left>right) return 0;
  dfs(nums,left+1,right);
  sum+=nums[left];
  return sum;
}
int SumVector(vector<int>&nums){
   int left = 0,right=nums.size()-1;
  return dfs(nums,left,right);
}
void sort(vector<int>&nums){
  for(int i=0;i<(int)nums.size();i++){
    for(int j=i+1;j<(int)nums.size();j++){
      if(nums[i]>nums[j]){
        swap(nums[i],nums[j]);
      }
    }
  }
}
void quickSort(int left,int right,vector<int>&nums){
  if(left>right) return;
  int i=left,j=right;
  int temp = nums[left];
  while(i!=j){
    while(nums[j]>=temp&&i<j) j--;
    while(nums[i]<=temp&&i<j) i++;
    if(i<j){
      int c = nums[i];
      nums[i] = nums[j];
      nums[j] = c;
    }
  }
  nums[left] = nums[i];
  nums[i] = temp;
  quickSort(left,i-1,nums);
  quickSort(i+1,right,nums);
}
int main(){
  vector<int> res = {1,3,2,5,4,6,7,2,2,1};
  //cout<<SumVector(res)<<endl;
  quickSort(0,res.size()-1,res);
  for(auto it:res){
    cout << it << " ";
  }
  return 0;
}
