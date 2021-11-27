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

class Solution {
public:
  bool isBalanced(TreeNode*&root){
    if(root==nullptr) return true;
    int left_h = height(root->left);
    int right_h = height(root->right);
    return (abs(right_h - left_h)<=1)&&isBalanced(root->left)&&isBalanced(root->right);
  }
  int height(TreeNode*&root){
    if(root==nullptr) return 0;
    return max(height(root->left),height(root->right))+1;
  }
};
