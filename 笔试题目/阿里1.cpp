#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  string ans="";
  unordered_map<char,int>map;
  while(n--){
    char c;
    cin>>c;
    ans.push_back(c);
    map[c]++;
  }
  vector<int>res;
  for(auto it:map){
    res.push_back(it.second);
  }
  if(res.size()==1){
    cout<<1<<endl;
    return 0;
  } 
  if(res[0]-res[1]>=0) cout<<1+res[1]<<endl;
  else cout <<1+res[0]<<endl;
  return 0;
}
