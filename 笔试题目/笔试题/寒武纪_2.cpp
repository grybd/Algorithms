#include <bits/stdc++.h>
using namespace std;

int main(){
  long N,M;
  cin>>N>>M;
  vector<long>ans(N,0);
  //priority_queue<long,vector<long>,less<long>>q;
  while(M--){
    long i,j,k;
    cin>>i>>j>>k;
    for(long index=i-1;index<j;index++){
      ans[index]+=k;
      //q.push(ans[index]);
    }
  }
  sort(ans.begin(),ans.end());
  cout<<ans[ans.size()-1];

}
