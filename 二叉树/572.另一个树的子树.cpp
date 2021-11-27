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
  bool isSubtree(TreeNode*root1,TreeNode*root2){
    if(!root1||!root2) return false;
    if(isSameTree(root1,root2)) return true;
    return isSubtree(root1->left,root2)||isSubtree(root1->right,root2);
  }
 bool isSameTree(TreeNode*root1,TreeNode*root2){
   if(!root1&&!root2) return true;
   if(!root1&&root2!=nullptr) return false;
   if(!root2&&root1!=nullptr) return false;
   if(root1->val!=root2->val) return false;
   bool left_t = isSameTree(root1->left,root2->left);
   bool right_t = isSameTree(root1->right,root2->right);
   return left_t&&right_t;
 }
};
