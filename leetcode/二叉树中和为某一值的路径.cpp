#include <vector>
using namespace std;

struct TreeNode{
  int val;
  struct TreeNode *left;
  struct TreeNode* right;
  TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    vector<vector<int>> res;
    vector<int>ans;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
     if(root==nullptr) return {{}};
     dfs(root,expectNumber);
     return res;
     }
     void dfs(TreeNode* root,int expectNumber)
     {
       if(root==nullptr) return;
       ans.push_back(root->val);
       if(expectNumber-root->val==0){
         res.push_back(ans);
         return ;
       }
       dfs(root->left,expectNumber-root->val);
       dfs(root->right,expectNumber-root->val);
     }
   };




    }
};
