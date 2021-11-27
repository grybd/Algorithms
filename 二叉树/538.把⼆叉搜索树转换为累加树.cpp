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

class Solution {
private:
   int pre;
   void traversal(TreeNode* root){
     if(root==nullptr) return;
     traversal(root->right);
     root->val+=pre;
     pre=root->val;
     traversal(root->left);
   }
public:
    TreeNode* convertBST(TreeNode* root) {
      pre=0;
      traversal(root);
      return root;
    }
};
