#include <stack>
using namespace std;

class CQueue{
public:
  stack<int> stack1,stack2;
  void appendTail(int value)
  {
    stack1.push(value);
  }

  int deleteHead(){
    if(stack2.empty())
    {
      while(!stack1.empty())
      {
        stack2.push(stack1.top());
        stack1.pop();
      }
    }

    if(stack2.empty())
    {
      return -1;
    }

    else{
      int item = stack2.top();
      stack2.pop();
      return item;
    }
  }
}
