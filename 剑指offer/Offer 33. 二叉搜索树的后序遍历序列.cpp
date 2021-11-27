#include <vector>
using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
      return dfs(postorder,0,postorder.size()-1);
    }
private:
    bool dfs(vector<int>&postorder,int i,int j){
      if(i>=j) return true;
      int p = i;
      while(postorder[p]<postorder[j]) p++;
      int tmp = p;
      while(postorder[p]>postorder[j]) p++;
      bool leftVerifyPostorder = dfs(postorder,i,tmp-1);
      bool rightVerifyPostorder = dfs(postorder,tmp,j-1);
      return p==j&&leftVerifyPostorder&&rightVerifyPostorder;
    }
};
