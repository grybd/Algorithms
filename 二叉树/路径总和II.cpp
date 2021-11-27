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
  vector<vector<int>> res;
  vector<int> paths;
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
      if(root==nullptr) return {};
      paths.push_back(root->val);
      traversal(root,targetSum-root->val);
      return res;
  }

  void traversal(TreeNode*root,int targetSum){
      if(!root->left&&!root->right&&targetSum==0){
        res.push_back(paths);
        return ;
      }
      if(!root->left&&!root->right) return ;
      if(root->left){
          targetSum-=root->left->val;
          paths.push_back(root->left->val);
          traversal(root->left,targetSum);
          paths.pop_back();
          targetSum+=root->left->val;
      }
      if(root->right){
          targetSum-=root->right->val;
          paths.push_back(root->right->val);
          traversal(root->right,targetSum);
          paths.pop_back();
          targetSum+=root->right->val;
       }

       return ;
  }
};
