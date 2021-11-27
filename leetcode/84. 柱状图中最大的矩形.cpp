#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
  //暴力解法
    int largestRectangleArea(vector<int>& heights) {
      int len = heights.size();
      if(len==0) return 0;
      int res;
      for(int i=0;i<len;i++){
        int left = i;
        while(left>0&&heights[i]<=heights[left-1]) left--;
        int right = i;
        while(right<len-1&&heights[i]<=heights[right+1]) right++;
        int width = right-left+1;
        res = max(res,width*heights[i]);
      }
    }
   //单调栈
 int largestRectangleAreaz_(vector<int>& heights) {
     int n = heights.size();
     vector<int> left(n), right(n);
     stack<int> mono_stack;
     for (int i = 0; i < n; ++i) {
         while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
             mono_stack.pop();
         }
         left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
         mono_stack.push(i);
     }
     mono_stack = stack<int>();
     for (int i = n - 1; i >= 0; --i) {
         while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
             mono_stack.pop();
         }
         right[i] = (mono_stack.empty() ? n : mono_stack.top());
         mono_stack.push(i);
     }
     int ans = 0;
     for (int i = 0; i < n; ++i) {
         ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
     }
     return ans;
 }
};
