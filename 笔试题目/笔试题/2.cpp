#include <bits/stdc++.h>
using namespace std;

int re_(string&str){
  int n=str.size();
  if(n==0) return -1;
  int count = str[0]-'0';
  if(n==1) return count;
  int i=0,j=1;
  string tmp;
  tmp.push_back(str[0]);
  int cout=0;
  while(j<n){
    if(str[j]=='+'||str[j]=='-'||str[j]-'0'>0||str[j]-'0'<9){
      i++;
      j++;
    }else{
      cout+=(str[i]-'0')*(str[j]-'0');
    }
  }

























    if(i+1<n&&str[i]=='*'){
      count = count*(str[i+1]-'0');
    }else if(str[i]=='+'){
      i++;
      if(i+1<n&&str[i+1]!='*'){
        count+=str[i]-'0';
      }else{
        count+=(str[i]-'0')*(str[i+1]-'0');
      }
    }else{
       i++;
       if(i+1<n&&str[i+1]!='*'){
          count-=str[i]-'0';
        }else{
          count-=(str[i]-'0')*(str[i+1]-'0');
        }
    }
    i++;
  }
  return count;
}
