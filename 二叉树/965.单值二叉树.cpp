#include <vector>
#include <stack>
#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution{
public:
  bool isUnivalTree(TreeNode*root){
    if(!root) return true;
    if((root->left&&root->left->val!=root->val)||(root->right&&root->right->val!=root->val))return false;
    return isUnivalTree(root->left)&&isUnivalTree(root->right);
  }
};
