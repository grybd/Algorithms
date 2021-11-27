#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //暴力解法
    int largestRectangleArea(vector<int>&height){
      int len = height.size();
      if(len==0) return 0;
      int res = 0;
      for(int i=0;i<len;i++){
        int left = i;
        int curheight = height[i];
        while(left>0&&height[left-1]>=height[left]){
          left--;
        }
        int right = i;
        while(right<len-1&&height[right+1]>=height[right]){
          right++;
        }
        int width = right - left+1;
        res = max(res,width*curheight);
      }
      return res;
    }
};
