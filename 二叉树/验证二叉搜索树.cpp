#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
  stack<char>sta;
  unordered_map<char,string>map={{'0',"0"},{'1',"1"},{'2',"10"},{'3',"11"},{'4',"100"},{'5',"101"},{'6',"110"},{'7',"111"},{'8',"1000"},{'9',"1001"}};
  string wy(string&s){
    string ans="";
    for(auto c:s){
      ans+=map[c];
    }
    /*
    for(auto c:ans){
     cout<<c<<" ";
   }*/
    //cout<<endl;
    reverse(ans.begin(),ans.end());
    int i=0;
    while(ans[i]=='0'){
      i++;
    }
    //if(ans.size()==0||ans.size()==1) return ans;
    string res = ans.substr(i,ans.size());
    /*
    for(auto c:res){
      cout<<c<<" ";
    }
    cout<<endl;*/
    sta.push(res[0]);
    for(int i=res.size()-1;i>=0;i--){
      if(sta.top()==res[i]) continue;
      //cout<<sta.top()<<endl;
      sta.push(res[i]);
    }
    int q_size=sta.size();
    string r="";
    for(int i=0;i<q_size;i++){
      r.push_back(sta.top());
      sta.pop();
    }
    return r;
  }
};

int main(){
  Solution s;
  int T;
  cin>>T;
  while(T--){
    string str;
    cin>>str;
    cout<<s.wy(str)<<endl;
  }
}
