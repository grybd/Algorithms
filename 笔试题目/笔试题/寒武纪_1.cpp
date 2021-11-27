#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int>ans;
  int num;
  cin>>num;
  int n = num;
  while(n--){
    int a;
    cin>>a;
    ans.push_back(a);
  }
  //cout<<ans.size()<<endl;
  for(auto b:ans){
    if(b<38){
       cout<<b<<endl;
       continue;
    }
    int d = b/5;
    int y = 5*d+5;
    if(y-b<3) cout<<y<<endl;
    else{
      cout<<b<<endl;
    }
  }
}
