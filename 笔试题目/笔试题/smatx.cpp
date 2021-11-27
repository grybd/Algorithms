#include <bits/stdc++.h>
using namespace std;
//"ABBCCCDD"

//AB2C3D2

string& changeStr(string&str){
   int n=str.size();
   int i=0;
   int k=0;
   while(i<n){
     int count=1;
     int j=i+1;
     while(j<n){
       if(str[i]==str[j]){
         j++;
         count++;
         continue;
       }
       if(count==1){
         str[k++]=str[i];
         break;
       }else{
         str[k++]=str[i];
         str[k++]=count+'0';
         break;
       }
     }
     if(j==n){
       if(count==1){
         str[k++]=str[i];
       }else{
         str[k++]=str[i];
         str[k++]=count+'0';
       }
     }
     i=j;
   }
   while (k<n) {
     str.pop_back();
     k++;
   }
   return str;
}

int main(){
  string str;
  cin>>str;
  cout<<changeStr(str);
  return 0;
}
