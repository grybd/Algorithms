#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int largestRectangleArea(vector<int>&heights){
      int size = heights.size();
      if(size==1) return heights[0];
      int res = 0;
      stack<int>stk;
      for(int i=0;i<size;i++){
        while(!stk.empty()&&heights[stk.top()]>heights[i]){
          int length = heights[stk.top()];
          stk.pop();
          int weight = i;
          if(!stk.empty()) weight = i-stk.top()-1;
          res = max(res,length*weight);
        }
        stk.push(i);
      }
      while(!stk.empty()){
        int length = heights[stk.top()];
        stk.pop();
        int weight = size;
        if(!stk.empty()){
          weight = size - stk.top() -1;
        }
        res = max(res,length*weight);
      }
      return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        vector<int>heights(matrix[0].size(),0);
        int maxArea = 0;
        for(int row=0;row<(int)matrix.size();row++){
            for(int col=0;col<(int)matrix[0].size();col++){
                if(matrix[row][col]=='1'){
                  heights[col]+=1;
                }else{
                  heights[col]=0;
                }
            }
            maxArea = max(maxArea,largestRectangleArea(heights));
        }
        return maxArea;
    }
};
