#include <bits/stdc++.h>
using namespace std;

class Sta{
public:
    stack<int>sta;
  public:
    void add(){
      if(!sta.empty()){
        int tmp = sta.top();
        sta.pop();
        sta.push(tmp+1);
      }
    }
    void push(){
      sta.push(1);
    }
    void pop(){
      if(!sta.empty()){
      sta.pop();
      }
    }
};
int main(){
  Sta sta_;
  int num;
  cin>>num;
  while(num--){
    string tmp;
    cin>>tmp;
    if(tmp=="Add"){
      sta_.add();
    }else if(tmp=="Push"){
      sta_.push();
    }else{
      sta_.pop();
    }
  }
  if(sta_.sta.empty()) cout<<"No number"<<endl;
  else cout<<sta_.sta.top()<<endl;
  return 0;
}
