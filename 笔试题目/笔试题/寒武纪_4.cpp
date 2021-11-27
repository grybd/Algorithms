#include<bits/stdc++.h>
using namespace std;
long getMinIndex(vector<long>&ans,long s,long e){
  long t = ans[s];
  long minIndex=s;
  for(long i=s;i<e;i++){
    if(ans[i]<t){
      t = ans[i];
      minIndex = i;
      continue;
    }
  }
  return minIndex;
}
int main(){
  long n;
  cin>>n;
  vector<long> ans;
  while(n--){
    long a;
    cin>>a;
    ans.push_back(a);
  }
  long i=0;
  long count=0;
  while(i<(long)ans.size()){
    long min_index = getMinIndex(ans,i,ans.size());
    if(ans[i]==ans[min_index]){
      i++;
      continue;
    }
    swap(ans[i],ans[min_index]);
    count++;
    i++;
  }
  cout<< count << endl;
}
