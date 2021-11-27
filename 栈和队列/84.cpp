#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
          int size = heights.size();
          if(size==1) return heights[0];
          int res=0;
          stack<int>sta;
          for(int i=0;i<size;i++){
             while(!sta.empty()&&heights[sta.top()]>=heights[i]){
                  int height = heights[sta.top()];
                  sta.pop();
                  int width=i;
                  if(!sta.empty()){
                    width = i-sta.top()-1;
                  }
                  res = max(res,height*width);
             }
             sta.push(i);
          }
          while(!sta.empty()){
            int width = size;
            int height = heights[sta.top()];
            sta.pop();
            if(!sta.empty()){
              width = size-sta.top()-1;
            }
            res = max(res,height*width);
          }
          return res;
    }
};
