#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
  private:
    bool traversal(TreeNode*cur,int count){
        if(!cur->left&&!cur->right&&count==0) return true;
        if(!cur->left&&!cur->right) return false;
        if(cur->left){
          count-=cur->left->val;
          if(traversal(cur->left,count)) return true;
        }
    }
  public:
      bool haspathsum(TreeNode*root,int sum){
        if(root==nullptr) return false;
        return traversal(root,sum-root->val);
      }
};
