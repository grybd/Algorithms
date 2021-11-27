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
  int height(TreeNode*root){
    if(!root) return 0;
    return max(height(root->left),height(root->right))+1;
  }
};
