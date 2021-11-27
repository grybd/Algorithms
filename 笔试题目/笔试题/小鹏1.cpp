#include <bits/stdc++.h>
using namespace std;

bool isValidIpNum(string&str){
  int n=str.size();
  if(n==0||n>3) return false;
  int i=0;
  int sum=0;
  while(--n){
    int a = (str[n]-'0')*pow(10,i);
    i++;
    sum+=a;
  }
  if(sum>255) return false;
  return true;
}
string isValidIp(string&s){
  int n=s.size()-1;
  string str = "";
  //vector<string>ans;
  int i=0;
  bool flag=false;
  int strlen=0;
  while(i<n){
    if(s[i]!='.'){
      i++;
      continue;
    }else{
      str = s.substr(strlen,i);
      cout<<strlen<<endl;
      flag &= isValidIpNum(str);
      i++;
      strlen = i;
    }
  }
  if(i==n&&flag){
    return "YES";
  }else{
    return "NO";
  }
}
int main(){
  string str;
  cin>>str;
  std::cout <<isValidIp(str)<<endl;
  return 0;
}
