#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
  int count=0;
 void dfs(vector<vector<int>>&nums,int start,int end,int n,int m){
     //cout<<"0"<<endl;
     if(start==n-1&&end==m-1){
      //cout<<"1"<<endl;
      count++;
      //cout<<count<<endl;
      return ;
     }
     if(start>n-1) return ;
     if(end>m-1) return ;
     if(nums[start][end]!=1){
      // cout<<"0"<<endl;
       dfs(nums,start+1,end,n,m);
       dfs(nums,start,end+1,n,m);
     }else{
       return ;
     }
 }
};
int main(){
  vector<vector<int>>res;
  int n;
  int m;
  cin>>n;
  cin>>m;
  int p = n;
  while(p--){
    vector<int>ans;
    int t = m;
    while(t--){
      int i;
      cin>>i;
      ans.push_back(i);
    }/*
    cout<<"\n"<<endl;
    for(int it:ans){
      cout<< it <<endl;
    }*/
    res.push_back(ans);
  }
  Solution s;
  s.dfs(res,0,0,n,m);
  cout<<s.count<<endl;
  //cout<<"anss"<<endl;
  return 0;
}
