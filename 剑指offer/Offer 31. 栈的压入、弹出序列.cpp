#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
      stack<int>sta;
      int i;
      for(int num:pushed){
        sta.push(num);
        while(!sta.empty()&&sta.top()==popped[i]){
          sta.pop();
          i++;
        }
      }
      return sta.empty();
    }
};
