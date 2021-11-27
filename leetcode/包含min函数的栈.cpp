#include <stack>
using namespace std;

class MinStack{
public:
  stack<int> sta,helper;
  MinStack(){
  }

  void push(int x){
    sta.push(x);
    if(helper.empty()||helper.top()>=x)
    {
      helper.push(x);
    }
  }

  void pop(){
    int temp=sta.top();
    sta.pop();
    if(temp==helper.top()){
       helper.pop();
    }
  }

  int top(){

    return sta.top();

  }

  int min(){
    return helper.top();

  }
};
