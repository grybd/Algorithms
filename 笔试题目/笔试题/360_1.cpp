#include <bits/stdc++.h>
using namespace std;

int getMaxD(vector<int>&ans){
  int n = (int)ans.size();
  int max_ = INT_MIN;
  for(int i=0;i<n;i++){
    int count = 1;
    int j=i;
    while(j>0){
      if(ans[j]>ans[j-1]){
        count++;
        j--;
        continue;
      }
      break;
    }
    int k=i;
    while(k<n){
      if(k+1<n&&ans[k]>ans[k+1]){
        //cout<<ans[k]<<endl;
        count++;
        k++;
        continue;
      }
      break;
    }
    max_ = max(max_,count);
  }
  return max_;
}

int main(){
  vector<int>ans;
  int n;
  cin>>n;
  while(n--){
    int a;
    cin>>a;
    ans.push_back(a);
  }
  int res = getMaxD(ans);
  cout<<res<<endl;
  return 0;
}
