#include <stack>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class MinStack_ {
public:
    /** initialize your data structure here. */
    MinStack_() {
     }
    void push(int x) {
        sta.push(x);
        if(!que.empty()&&x>=que.back()) que.push_back(que.back());
        else if(que.empty()){
            que.push_back(x);
        }else{
            que.push_back(x);
        }
    }
    void pop() {
      if(sta.empty()||que.empty()) return ;
        sta.pop();
        que.pop_back();
    }
    int top() {
      if(sta.empty()) return -1;
      return sta.top();
    }
    int min() {
      if(que.empty()) return -1;
      return que.back();
    }
  private:
    stack<int> sta;
    deque<int> que;
};

class MinStack {
    stack<int> x_stack;
    stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }

    void push(int x) {
        x_stack.push(x);
        min_stack.push(std::min(min_stack.top(), x));
    }

    void pop() {
        x_stack.pop();
        min_stack.pop();
    }

    int top() {
        return x_stack.top();
    }

    int min() {
        return min_stack.top();
    }
};
