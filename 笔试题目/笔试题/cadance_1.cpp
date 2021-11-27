#include <bits/stdc++.h>
using namespace std;

string MaxString(string str){
  int str_size = str.size();
  if(str[0]=='-'){
    string ans;
    int i=0;
    while(i<str_size){
      int a = str[i]-'0';
      if(a<=6){
        ans.push_back(str[i]);
        i++;
        continue;
      }
      ans.push_back('6');
      break;
    }
    if(i==str_size){
      ans.push_back('6');
      return ans;
    }
    while(i<str_size){
      ans.push_back(str[i]);
      i++;
    }
    return ans;
  }
  string ans;
  int i=0;
  while(i<str_size){
    int a=str[i]-'0';
    if(a>=6){
      ans.push_back(str[i]);
    }else{
      ans.push_back('6');
      break;
    }
    i++;
  }
  while(i<str_size){
    ans.push_back(str[i]);
    i++;
  }
   return ans;
  }

int main(){
  int n;
  cin>>n;
  string n_=to_string(n);
  cout<<MaxString(n_);
  return 0;
}
