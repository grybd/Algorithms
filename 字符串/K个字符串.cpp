#include <bits/stdc++.h>
using namespace std;

string s;
int k;

int main(){
  cin>>s;
  cin>>k;
  set<string>set;
  int ls = s.size();
  for(int i=0;i<ls;i++){
    string tem;
    for(int j=i;j<ls;j++){
      tem+=s[j];
      if((int)set.size()>=k){
        if(tem>=*(--set.end())){
          break;
        }
      }
      set.insert(tem);
      if((int)set.size()>k){
        set.erase(--set.end());
      }
    }
  }
  cout<<*(--set.end())<<endl;
  return 0;
}
