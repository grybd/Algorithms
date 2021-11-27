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
    vector<int>res;
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        if(res.size()<2) return root->val;
        int minVal=INT_MAX;
        for(int i=1;i<(int)res.size();i++){
          minVal=min(res[i]-res[i-1],minVal);
        }
        return minVal;
    }
    void traversal(TreeNode* root){
      if(!root) return ;
      traversal(root->left);
      res.push_back(root->val);
      traversal(root->right);
    }
    //递归解法//太经典了！！！
    TreeNode* prev=nullptr;
    int minVal=INT_MAX;
    int _getMinimumDifference(TreeNode* root) {
        _traversal(root);
        return minVal;
    }
    void _traversal(TreeNode*root){
      if(!root) return ;
      _traversal(root->left);
      if(prev!=nullptr){
        minVal=min(minVal,root->val-prev->val);
      }
      prev=root;
      _traversal(root->right);
    }
};
