#include <bits/stdc++.h>
using namespace std;

class MyStack{
  private:
      stack<int>stacks;
      stack<int>minstacks;
      stack<int>maxstacks;
  public:
      void push(int e){
        stacks.push(e);
        if(minstacks.empty()||e<minstacks.top()){
          minstacks.push(e);
        }else if(e>=minstacks.top()){
          minstacks.push(minstacks.top());
        }
        if(maxstacks.empty()||e>maxstacks.top()){
          maxstacks.push(e);
        }else if(e<=maxstacks.top()){
          maxstacks.push(maxstacks.top());
        }
      }
     void pop(){
        stacks.pop();
        minstacks.pop();
        maxstacks.pop();
      }
      int top(){
        return stacks.top();
      }
      int getMin(){
        return minstacks.top();
      }
      int getMax(){
        return maxstacks.top();
      }
};
