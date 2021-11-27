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
  bool isSymmetric(TreeNode*root){
    return isMirror(root,root);
  }
  bool isMirror(TreeNode*p,TreeNode*q){
    if(!p&&!q) return true;
    if(!p||!q) return false;
    if(p->val!=q->val) return false;
    return isMirror(p->left,q->right)&&isMirror(p->right,q->left);
  }
};
