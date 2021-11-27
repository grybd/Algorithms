#include <bits/stdc++.h>
using namespace std;

int main(){
  string str;
  while(getline(cin,str)){
    vector<char>cha;
    vector<char>inte;
    string ans="";
      int i=0;
      while(i<(int)str.size()){
      int count=1;
      int j=i+1;
      while(j<(int)str.size()){
        if(str[i]==str[j]){
          j++;
          count++;
        }else{
          cha.push_back(str[i]);
          inte.push_back(count+'0');
          break;
        }
      }
      if(j==(int)str.size()){
        cha.push_back(str[i]);
        inte.push_back(count+'0');
      }
      i = j;
    }
    bool flag = false;
    for(auto it:inte){
      if(it>'1') flag = true;
    }
    if(!flag){
      cout<<str;
    }else{
         for(int i=0;i<(int)inte.size();i++){
           if(inte[i]=='1'){
             ans.push_back(cha[i]);
             continue;
           }else{
             ans.push_back(inte[i]);
             ans.push_back(cha[i]);
           }
         }
      }
      cout<<ans<<endl;
  }
  return 0;
}
