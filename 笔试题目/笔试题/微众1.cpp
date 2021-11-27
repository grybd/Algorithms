#include <bits/stdc++.h>
using namespace std;

vector<int> find(vector<int>&ans){
  vector<int>res;
  for(int i=0;i<(int)ans.size();i++){
    if(res.empty()){
      res.push_back(ans[i]);
      continue;
    }
    int k=0;
    int o = 0;
    for(int j=0;i>0&&j<=i-1;j++){
      if((j+1)%2==1){
        k+=res[j];
      }else{
        o+=res[j];
      }
    }
    int tmp = k-o;
    if((i+1)%2==0){
      int a = tmp-ans[i];
      res.push_back(a);
    }else{
      int a = ans[i]-tmp;
      res.push_back(a);
    }
  }
  return res;
}

int main(){
   vector<int>ans;
   vector<int> res;
   int n;
   cin>>n;
   while(n--){
     int in;
     cin>>in;
     ans.push_back(in);
   }
   res = find(ans);
   for (int a:res){
     cout <<a<<" ";
   }
   cout << endl;
   return 0;
}
