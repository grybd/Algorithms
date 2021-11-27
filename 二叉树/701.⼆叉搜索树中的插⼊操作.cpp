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
    //有返回值的情况
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr){
            TreeNode* newNode=new TreeNode(val);
            return newNode;
        }
        if(val<root->val) root->left=insertIntoBST(root->left,val);
        if(val>root->val) root->right=insertIntoBST(root->right,val);
        return root;
    }
    //没有返回值的情况
    TreeNode*_insertIntoBST(TreeNode* root, int val){
      cur=new TreeNode(0);
      if(root==nullptr)
      {
        root = new TreeNode(val);
      }
      Traversal(root,val);
      return root;
    }
  private:
    TreeNode* cur;
    void Traversal(TreeNode*root,int val){
      if(root==nullptr){
        TreeNode* newNode=new TreeNode(val);
        if(val<cur->val) cur->left=newNode;
        else  cur->right=newNode;
        return;
      }
      cur=root;
      Traversal(root->left,val);
      Traversal(root->right,val);
      return ;
    }
};
