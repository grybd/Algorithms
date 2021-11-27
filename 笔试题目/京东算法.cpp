#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maximalRectangle(vector<vector<char>>&matrix){
      int m = matrix.size();
      if(m==0) return 0;
      int width[matrix.size()][matrix[0].size()];
      int maxArea = 0;
      for(int row=0;row<(int)matrix.size();row++){
        for (int col=0;col<(int)matrix[0].size();col++){
            //更新width
            if(matrix[row][col]=='1'){
              if(col==0){
                width[row][col] = 1;
              }else{
                width[row][col]=width[row][col-1]+1;
              }
            }else{
              width[row][col]=0;
            }
            int minWidth = width[row][col];
            for(int up_row=row;up_row>=0;up_row--){
              int height = row-up_row+1;
              minWidth = min(minWidth,width[up_row][col]);
              maxArea = max(maxArea,height*minWidth);
            }
        }
      }
      return maxArea;
}
};
