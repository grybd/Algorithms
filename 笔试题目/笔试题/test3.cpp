#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int n=s.size();
    string s1="";
    while(--n){
        s1.push_back(s[n]);
    }
    s1.push_back(s[0]);
    string ans = "";
    string s2="";
    int k=0;
    while(k<(int)s1.size()){
      if(s1[k]!=' '){
        s2.push_back(s1[k]);
      }else{
        reverse(s2.begin(),s2.end());
        s2.push_back(' ');
        ans+=s2;
        s2.clear();
      }
      k++;
    }
    reverse(s2.begin(),s2.end());
    ans+=s2;
    for(int i=0;i<(int)ans.size();i++){
      cout << ans[i];
    }
    cout << endl;
}
