#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
  //前序迭代法
  vector<int>preorderTraversal(TreeNode* root){
    stack<TreeNode*>st;
    vector<int> res;
    st.push(root);
    while(!st.empty()){
      TreeNode* node=st.top();
      st.pop();
      if(node!=nullptr) res.push_back(node->val);
      else continue;
      st.push(node->right);
      st.push(node->left);
    }
    return res;
  }
  //中序遍历迭代法
  vector<int>inorderTraversal(TreeNode* root){
    vector<int> res;
    stack<TreeNode*>st;
    TreeNode* cur=root;
    while(cur!=nullptr||!st.empty()){
      if(cur!=nullptr)
      {
        st.push(cur);
        cur=cur->left;
      }
      else{
        cur=st.top();
        st.pop();
        res.push_back(cur->val);
        cur=cur->right;
      }
    }
    return res;
  }
  //后序遍历
  vector<int> postorderTraversal(TreeNode*root){
    vector<int>res;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
      TreeNode* node=st.top();
      st.pop();
      if(node!=nullptr) res.push_back(node->val);
      else continue;
      st.push(node->left);
      st.push(node->right);
    }
    reverse(res.begin(),res.end());
    return res;
  }
  //前序遍历递归写法
  void _preorderTraversal(TreeNode*root,vector<int>&res){
    if(root==nullptr) return;
     res.push_back(root->val);
    _preorderTraversal(root->left,res);
    _preorderTraversal(root->right,res);
  }
  //中序
  void _inorderTraversal(TreeNode*root,vector<int>&res){
    if(root==nullptr) return;

    _inorderTraversal(root->left,res);
    res.push_back(root->val);
    _inorderTraversal(root->right,res);
  }

  //后序
  void _postorderTraversal(TreeNode*root,vector<int>&res){
    if(root==nullptr) return;

    _postorderTraversal(root->left,res);
    _postorderTraversal(root->right,res);
    res.push_back(root->val);
  }  
};
