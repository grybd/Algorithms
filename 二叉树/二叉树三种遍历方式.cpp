#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
public:
  TreeNode* left;
  TreeNode* right;
  int val;
  TreeNode(int val_):left(nullptr), right(nullptr),val(val_){}
};

class Solution{
public:
  virtual void traversal(TreeNode* cur, vector<int>&vec){
    if(cur == nullptr) return;
    vec.push_back(cur->val);
    traversal(cur->left,vec);
    traversal(cur->right,vec);
  }
  vector<int> preorderTraversal(TreeNode* root){
    vector<int> result;
    traversal(root,result);
    return result;
  }
};

class Solution_1:public Solution{
  void traversal(TreeNode* cur, vector<int>&vec){
    if(cur == nullptr) return;
    traversal(cur->left,vec);
    traversal(cur->right,vec);
    vec.push_back(cur->val);
  }

  vector<int> HTraversal(TreeNode* root){
    vector<int> result;
    traversal(root,result);
    return result;
  }
};

class Solution_2:public Solution{
  void traversal(TreeNode* cur, vector<int>&vec){
    if(cur == nullptr) return;
    traversal(cur->left,vec);
    vec.push_back(cur->val);
    traversal(cur->right,vec);
  }
  vector<int> inTraversal(TreeNode* root){
    vector<int> result;
    traversal(root,result);
    return result;
  }
};

//二叉树的迭代遍历

class Solution_3{
public:
  vector<int> preorderTraversal(TreeNode* root){
    stack<TreeNode*>st;
    vector<int>result;
    if(root==nullptr) return result;
    st.push(root);
    while(!st.empty()){
      TreeNode* node = st.top();
      st.pop();
      result.push_back(node->val);
      if(node->right) st.push(node->right);
      if(node->left) st.push(node->left);
    }
    return result;
  }
};

class Solution_4{
public:
  vector<int> inorderTraversal(TreeNode* root){
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* cur=root;
    while(cur!=nullptr||!st.empty()){
      if(cur!=nullptr){
        st.push(cur);
        cur = cur->left;
      }else{
        cur = st.top();
        st.pop();
        result.push_back(cur->val);
        cur = cur->right;
      }
    }
    return result;
  }
};


class Solution_5{
  vector<int> postorderTraversal(TreeNode* root){
    vector<int> result;
    stack<TreeNode*> st;
    if(root==nullptr) return result;
    st.push(root);
    while(!st.empty()){
      TreeNode* node = st.top();
      st.pop();
      result.push_back(node->val);
      if(node->left) st.push(node->left);
      if(node->right) st.push(node->right);
    }
    reverse(result.begin(),result.end());
    return result;
  }
};

//二叉树的层序遍历
class Solution_6 {
public:
  vector<vector<int>> levelOrder(TreeNode* root){
    queue<TreeNode*> que;
    if(root != nullptr) que.push(root);
    vector<vector<int>> result;
    while(!que.empty()){
      int size = que.size();
      vector<int> vec;
      for(int i=0;i<size;i++){
        TreeNode* node = que.front();
        que.pop();
        vec.push_back(node->val);
        if(node->left) que.push(node->left);
        if(node->right) que.push(node->right);
      }
      result.push_back(vec);
    }
    return result;
  }
};

//二叉树的右视图
class Solution_7{
public:
  vector<int> rightSideview(TreeNode* root){
    queue<TreeNode*> que;
    if(root!=nullptr) que.push(root);
    vector<int> result;
    while(!que.empty()){
      int size = que.size();
      for(int i=0;i<size;i++){
        TreeNode* node = que.front();
        que.pop();
        if(i==(size-1)) result.push_back(node->val);
        if(node->left) que.push(node->left);
        if(node->right) que.push(node->right);
      }
    }
    return result;
  }
};

struct Node{
  int val;
  Node* left;
  Node* right;
  Node* next;
};
class Solution_8 {
public:
  Node* connect(Node* root){
    queue<Node*> que;
    Node* preNode=nullptr;
    Node* node = nullptr;
    if(root!=nullptr) que.push(root);
    while(!que.empty()){
      int size = que.size();
      for(int i=0;i<size;i++){
        if(i==0){
          Node* node = que.front();
          que.pop();
          preNode = node;
        }else{
          Node* node = que.front();
          que.pop();
          preNode->next = node;
          preNode = preNode->next;
        }
        if(node->left) que.push(node->left);
        if(node->right) que.push(node->right);
      }
      preNode->next = nullptr;
    }
    return root;
  }
};


//反转二叉树
