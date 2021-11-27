#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

unordered_map<TreeNode*, int>mem;
int rob(TreeNode*root){
  if(root==nullptr) return 0;
  //利用备忘录
  if(mem.count(root)) return mem[root];
  int rob_it = root->val;
  if(root->left){
    rob_it+=rob(root->left->left)+rob(root->left->right);
  }
  if(root->right){
    rob_it+=rob(root->right->left)+rob(root->right->right);
  }
  int not_rob = rob(root->left)+rob(root->right);
  int ans = max(rob_it,not_rob);
  mem[root] = ans;
  return ans;
}
