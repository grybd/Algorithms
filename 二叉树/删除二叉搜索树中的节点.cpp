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
    TreeNode* deleteNode(TreeNode* root, int key) {
      //如果一直找到空都找不到key就直接返回
        if(root==nullptr) return root;
      //找到节点，分情况讨论
        if(root->val==key){
          if(root->left==nullptr) return root->right;
          else if(root->right==nullptr) return root->left;
          else{
            TreeNode*cur=root->right;
            while(cur->left!=nullptr){
              cur=cur->left;
            }
            cur->left=root->left;
            TreeNode*temp=root;
            root=root->right;
            delete temp;
            return root;
          }
        }
        if(key<root->val) root->left=deleteNode(root->left,key);
        if(key>root->val) root->right=deleteNode(root->right,key);
        return root;
    }
};
