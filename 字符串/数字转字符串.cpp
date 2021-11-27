#include <bits/stdc++.h>
using namespace std;

string num2str(double i){
  stringstream ss;
  ss<<i;
  return ss.str();
}

int str2num(string s){
  int num;
  stringstream ss(s);
  ss>>num;
  return num;
}

int main(){
  int i = 123;
  string s = "1233";
  cout<<num2str(i)<<" "<<str2num(s)<<endl;
  return 0;
}
