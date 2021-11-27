#include<bits/stdc++.h>
using namespace std;
using namespace std;

class Solution{
  bool isValid(string&str){
    stack<char>sta;
    int n=str.size();
    sta.push(str[0]);
    for (int i=1;i<n;i++){
      char c = sta.top();
      if(c=='0'&&str[i]=='1'){
          sta.pop();
          continue;
        }
      if(c=='2'&&str[i]=='3'){
          sta.pop();
          continue;
        }
        sta.push(str[i]);
      }
    if(sta.empty()) return true;
    return false;
  }
public:
  int count=0;
  vector<int>ans;
  string text="";
  void backtrack(string&s,int n,int st){
    if(n>=(int)s.size()){
      ans.push_back(count);
      return;}
      for(int i=st;i<(int)s.size();i++){
        text+=s[i];
        if(isValid(text)){
          count++;
        }
        backtrack(s,n+1,st+1);
        text.pop_back();
      }
  }
  int bfs(string&str){
    backtrack(str,0,0);
    return count;
  }
};
int main(){
  stack<char>sta;
  int num;
  cin>>num;
  string str;
  cin >> str;
  Solution s;
  int temp=s.ans[0];
  for(int i=0;i<(int)s.ans.size();i++)

  cout << s.count<<endl;
}
