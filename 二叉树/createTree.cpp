#include <vector>
#include <stack>
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(char x):val(x),left(nullptr),right(nullptr){}
};

class Solution{
public:
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
  TreeNode* root;
  Solution s;
  s.create_tree(root);
  s.printTree(root);
}
