#include <vector>
#include <stack>
#include <iostream>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q)
  {
    if(root==nullptr||p==root||q==root) return root;
    TreeNode* left=lowestCommonAncestor(root->left,p,q);
    TreeNode* right=lowestCommonAncestor(root->right,p,q);
    if(left==nullptr&&right==nullptr) return nullptr;
    else if(left!=nullptr&&right!=nullptr) return root;
    else {
      return left==nullptr?right:left;
    }
  }
};
