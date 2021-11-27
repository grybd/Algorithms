
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
    int countNodes(TreeNode* root) {
      if(root==nullptr) return 0;
      int leftN=countNodes(root->left);
      int rightN=countNodes(root->right);
      return 1+leftN+rightN;
    }
};
