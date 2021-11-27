#include <stack>
using namespace std;
class CQueue{
public:
  CQueue(){}
  void appendTail(int value){
    sta2.push(value);
  }
  int deleteHead(){
    if(sta1.empty()){
      while(!sta2.empty()){
        int temp = sta2.top();
        sta2.pop();
        sta1.push(temp);
      }
    }
    if(sta1.empty()) return -1;
    int tmp = sta1.top();
    sta1.pop();
    return tmp;
  }
private:
  stack<int> sta1;
  stack<int> sta2;
};
