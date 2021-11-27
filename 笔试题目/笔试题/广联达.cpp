#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<int>>ans;
  int n;
  int b;
  cin>>n>>b;
  while(n--){
    int u,v,r;
    cin>>u>>v>>r;
    ans.push_back({u,v,r});
  }
  for(int i=0;i<(int)ans.size();i++){
    if(2*ans[i][2]>=b){
      cout<< i+1 << endl;
      break;
    }
    if(i+1<(int)ans.size()){
      int len = abs(ans[i][1]-ans[i+1][1]);
      int R = ans[i][2]+ans[i+1][2]+len;
      if(R>=b) {
        cout<< i+1 <<endl;
        break;
      }
    }

  }
  return 0;
}
