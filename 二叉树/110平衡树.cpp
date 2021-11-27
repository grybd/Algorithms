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
  bool isBalanced(TreeNode*root){
    if(!root) return true;
    int leftD=getD(root->left);
    int rightD=getD(root->right);
    return !(abs(leftD-rightD)>1)&&isBalanced(root->left)&&isBalanced(root->right);
  }

  int getD(TreeNode*root){
    if(!root) return 0;
    int l=getD(root->left);
    int r=getD(root->right);
    return 1+max(l,r);
  }
};
