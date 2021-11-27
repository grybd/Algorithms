#include <bits/stdc++.h>
using namespace std;

int f(set<int>&nums,int n){
  if(n==0) return 1;
  if(n==1&&nums.find(n)==nums.end()) return 1;
  if(n==1&&nums.find(n)!=nums.end()) return 0;
  if(nums.find(n)==nums.end()){
     int left = f(nums,n-1);
     int right = f(nums,n-2);
     return left + right;
  }else{
    return 0;
  }
}
int main(){
  int num1,num2;
  set<int>ans;
  cin>>num1>>num2;
  while(num2--){
    int in;
    cin>>in;
    ans.insert(in);
  }
  cout << f(ans,num1) <<endl;
  return 0;
}
