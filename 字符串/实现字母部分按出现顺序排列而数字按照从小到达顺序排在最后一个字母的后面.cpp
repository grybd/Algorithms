#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    static bool cmp(string s1,string s2){
       return stoll(s1)<stoll(s2);
    }
    string char_and_return(string text_source){
      vector<string>vec;
      stringstream ss(text_source);
      string s;
      string res="";
      while(getline(ss,s,' ')){
        if(s[0]>='0'&&s[0]<='9')vec.push_back(s);
        else res+=s+" ";
      }
      if(res!="") res.pop_back();
      sort(vec.begin(),vec.end(),cmp);
      if(res==""){
        int i=0;
        for(int i=0;i<(int)vec.size()-1;i++){
           res+=vec[i]+" ";
        }
        res+=vec[i];
      }else{
        int i;
        for(i=0;i<(int)vec.size();i++){
          res+=" "+vec[i];
        }
      }
      return res;
    }
};
