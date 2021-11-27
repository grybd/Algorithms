#include <vector>
#include <stack>
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode{
  char val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
class Solution{
public:
  TreeNode*mergeTrees(TreeNode*t1,TreeNode*t2)
  {
      if(t1==nullptr) return t2;
      if(t2==nullptr) return t1;
      TreeNode* root=new TreeNode(t1->val+t2->val);
      root->left=mergeTrees(t1->left,t2->left);
      root->right=mergeTrees(t1->right,t2->right);
      return root;
  }
};
