#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(),m=matrix[0].size();
        vector<int>ans;
        int maxAre=INT_MIN;
        for(int i=0;i<n;i++){
            int j=i;
            int w,h;
            while(j>=0){
              if(matrix[i][j]=='0') ans.push_back(0);
              else{
                h++;

              }
            }
        }

    }
};
