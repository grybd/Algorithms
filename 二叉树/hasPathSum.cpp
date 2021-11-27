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
  bool hasPathSum(TreeNode* root, int targetSum) {
      if(root==nullptr) return false;
      return traversal(root,targetSum-root->val);
  }

  bool traversal(TreeNode*root,int targetSum){
      if(!root->left&&!root->right&&targetSum==0) return true;
      if(!root->left&&!root->right) return false;

      if(root->left){
          targetSum-=root->left->val;
          if(traversal(root->left,targetSum)) return true ;
          targetSum+=root->left->val;
      }
      if(root->right){
          targetSum-=root->right->val;
          if(traversal(root->right,targetSum)) return true ;
          targetSum+=root->right->val;
       }
       return false;
  }

  void create_tree(TreeNode*&root){
    int ch;
    cin>>ch;
    if(ch==0)
    {
      root=nullptr;
      return;
    }
    else{
      root=new TreeNode(ch);
      if(!root) exit(0);
      root->val=ch;
      create_tree(root->left);
      create_tree(root->right);
    }
  }

  void printTree(TreeNode*root){
    if(root==nullptr) return;
    cout<<root->val<<' ';
    printTree(root->left);
    printTree(root->right);
  }
};

int main(){
  /*
  TreeNode* root=new TreeNode(1);
  TreeNode* a=new TreeNode(2);
  TreeNode* b= new TreeNode(3);
  TreeNode* c=new TreeNode(4);
  TreeNode* d=new TreeNode(5);
  root->left=a;
  root->right=d;
  a->left=b;
  a->right=c;*/
  TreeNode* root;
  Solution s;
  s.create_tree(root);
  TreeNode*head=root;
  //cout<<s.hasPathSum(root,6);
  s.printTree(head);
}
