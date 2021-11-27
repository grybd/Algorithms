#include<bits/stdc++.h>
using namespace std;

bool isRightChoose(int start,int end,vector<vector<int>>&ans,int p){
    if(start==end) return false;
    if(ans[start][0]==ans[end][0]) return false;
    else if(min(ans[start][1],ans[end][1])>p) return false;
    else{
      return true;
    }
}

void backtrack(vector<vector<int>>&ans,int index,int len,int&count,int p){
  if(index>=len-1){
    return;
  }
  for(int i=index;i<len;i++){
    if(i>0&&isRightChoose(index,i,ans,p)){
      count++;
      backtrack(ans,index+1,len,count,p);
    }
  }
}

int getMinCost(vector<vector<int>>&ans,int p){
   int n = ans.size();
   if(n==0) return 0;
   static int count=0;
   backtrack(ans,0,n,count,p);
   return count;
}

int main(){
  vector<vector<int>>ans;
  int n,k,p;
  cin>>n>>k>>p;
  while(n--){
    int color,cost;
    cin>>color>>cost;
    ans.push_back({color,cost});
  }
  int res = getMinCost(ans,p);
  cout<<res<<endl;
  return 0;
}
