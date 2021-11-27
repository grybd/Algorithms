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
    int sumOfLeftLeaves(TreeNode* root) {
      if(root==nullptr) return 0;
      int leftD=sumOfLeftLeaves(root->left);
      int rightD=sumOfLeftLeaves(root->right);
      int res=0;
      if(root->left&&root->left->left==nullptr&&root->left->right==nullptr) res+=root->left->val;
      res=leftD+rightD+res;
      return res;
    }
    //迭代法求左叶子节点之和
    int res=0;
    int _sumofLeftLeaves(TreeNode* root){
      stack<TreeNode*>sta;
      if(root==nullptr) return 0;
      sta.push(root);
      while(!sta.empty()){
        TreeNode* node=sta.top();
        sta.pop();
        if(node->left!=nullptr&&node->left->left==nullptr&&node->left->right==nullptr)
        {
          res=+root->left->val;
        }
        if(node->right) sta.push(node->right);
        if(node->left) sta.push(node->left);
      }
      return res;
    }
};

int main(){
  TreeNode* root = new TreeNode(1);
  TreeNode* first=new TreeNode(2);
  TreeNode* second=new TreeNode(3);
  TreeNode* four = new TreeNode(4);
  root->left=first;
  first->left=second;
  root->right=four;
  Solution s;
  s._sumofLeftLeaves(root);
  cout << s.res;
}
