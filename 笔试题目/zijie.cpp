#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
vector<int>preorder(int numcourse,vector<vector<int>>&pre){
    if(pre.size()==0) return {};
    vector<int>ans;
    int n = pre.size();
    ans.push_back(pre[0][0]);
    ans.push_back(pre[0][1]);
    if(pre.size()==1) return ans;
    for(int i=1;i<n;i++){
      int tmp_0 = pre[i][0];
      int tmp_1 = pre[i][1];
      int j = i+1;
      if(pre[j][1]==tmp_0){
        ans.clear();
        continue;
      }
      while(j<n){
        if (pre[j][0]==tmp_1){
          ans.push_back(pre[j][0]);
          tmp_1 = pre[j][1];
        }
        j++;
      }
      return ans;
    }
  }
};
