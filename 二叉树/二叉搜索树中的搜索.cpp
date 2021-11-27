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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==nullptr) return nullptr;
        if(root->val==val) return root;
        if(root->val>val) return searchBST(root->left,val);
        if(root->val<val) return searchBST(root->right,val);
        return nullptr;
    }
    //迭代法
    TreeNode* _searchBST(TreeNode* root, int val){
      if(!root) return nullptr;
      while(root)
      {
        if(root->val>val) root=root->left;
        else if(root->val<val) root=root->right;
        else return root;
      }
      return nullptr;
    }
};
