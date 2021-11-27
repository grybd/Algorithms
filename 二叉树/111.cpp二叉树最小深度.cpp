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

class Solution{
public:
  //递归解法
  int minDepth(TreeNode* root) {
    if(root==nullptr) return 0;
    int leftD=minDepth(root->left);
    int rightD=minDepth(root->right);
    if(root->left==nullptr&&root->right!=nullptr) return 1+rightD;
    if(root->right==nullptr&&root->left!=nullptr) return 1+leftD;
    return 1+min(leftD,rightD);
    }
  //迭代法
  int _minDepth(TreeNode* root){
    queue<TreeNode*>q;
    if(root!=nullptr) q.push(root);
    int depth=0;
    TreeNode* node;
    while(!q.empty()){
      int n=q.size();
      depth++;
      for(int i=0;i<n;i++)
      {
        node=q.front();
        q.pop();
        if(node->left==nullptr&&node->right==nullptr)
        {
          return depth;
        }
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
      }
    }
    return depth;
  }
};
