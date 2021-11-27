#include <algorithm>
#include <queue>
using namespace std;
class MaxQueue {
  int q[20000];
  int begin=0,end=0;
  queue<int> q1;
  deque<int> d;
public:
  //暴力解法
    MaxQueue_(){}
    int max_value_() {
      int ans=-1;
      for(int i=begin;i!=end;++i){
        ans = max(ans,q[i]);
      }
      return ans;
    }
    void push_back_(int value) {
      q[end++]=value;
    }
    int pop_front_() {
      if(begin==end) return -1;
      return q[begin++];
    }
//维护一个单调的双端队列
    MaxQueue() {}
    int max_value() {
      if(d.empty()) return -1;
      return d.front();
    }
    void push_back(int value) {
      while(!d.empty()&&d.back()<value){
        d.pop_back();
      }
      d.push_back(value);
      q1.push(value);
    }
    int pop_front() {
      if(q1.empty()) return -1;
      int ans=q1.front();
      if(ans==d.front()) d.pop_front();
      q1.pop();
      return ans;
    }
};
