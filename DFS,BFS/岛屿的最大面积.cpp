#include <bits/stdc++.h>
using namespace std;
//"ABBCCCDD"

//AB2C3D2

string changeStr(string&str){
   int n=str.size();
   vector<int>temp_1;
   vector<char>temp_2;
   for(int i=0;i<n;i++){
     int count=1;
     int j=i;
     while(j<n){
       if(str[i]==str[j]){
         j++;
         continue;
       }
       count++;
       temp_1.push_back(count);
       temp_2.push_back(str[i]);
     }
   }
   string s;
   int m=temp_1.size();
   for(int k=0;k<m;k++){
     if(temp_2[k]!=1){
       s.push_back(temp_1[k]);
       s.push_back(temp_2[k]);
     }else{
       s.push_back(temp_1[k]);
       continue;
     }
   }
   return s;
}

int mian(){
  string str;
  cin>>str;
  cout<<changeStr(str);
  return 0;
}
