#include <vector>
#include <stack>
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    bool judge(TreeNode* left, TreeNode* right)
    {
        if(left==nullptr&&right==nullptr) return true;
        if(left==nullptr||right==nullptr) return false;
        if(left->val!=right->val) return false;
        return judge(left->left,right->right)&&judge(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
      if(root==nullptr) return true;
      return judge(root->left, root->right);
    }
};
