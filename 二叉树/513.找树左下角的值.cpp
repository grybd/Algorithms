#include <vector>
#include <stack>
#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

struct TreeNode{
  char val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
class Solution{
public:
  int maxLen=INT_MIN;
  int maxleftValue;
  void traversal(TreeNode*root,int leftLen){
    if(root->left==nullptr&&root->right==nullptr){
      if(leftLen>maxLen){
        maxLen=leftLen;
        maxleftValue=root->val;
      }
    }
  if(root->left){
    leftLen++;
    traversal(root->left,leftLen);
    leftLen--;
  }
  if(root->right){
    leftLen++;
    traversal(root->right,leftLen);
    leftLen--;
  }
}
int findBottomLeftValue(TreeNode*root){
  if(root==nullptr) return 0;
  traversal(root,0);
  return maxleftValue;
}
//迭代法
int _findBottomLeftValue(TreeNode*root){
  queue<TreeNode*>q;
  if(root!=nullptr) q.push(root);
  int res=0;
  while(!q.empty()){
    int n=q.size();
    for(int i=0;i<n;i++){
      TreeNode* node=q.front();
      q.pop();
      if(i==0) res=node->val;
      if(node->left) q.push(node->left);
      if(node->right) q.push(node->right);
    }

  }
  return res;
}

};
