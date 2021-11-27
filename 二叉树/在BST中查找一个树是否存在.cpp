#include <limits.h>
#include <algorithm>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class solution{
public:
  bool isInBST(TreeNode* root, int target){
    if(root==nullptr) return false;
    if(root->val==target) return true;
    if(root->val<target) return isInBST(root->right,target);
    if(root->val>target) return isInBST(root->left,target);
  }
  TreeNode* insertIntoBST(TreeNode* root,int val){
    if(root==nullptr) return new TreeNode(val);
    if(root->val<val) root->right = insertIntoBST(root->right,val);
    if(root->val<val) root->left = insertIntoBST(root->left,val);
    return root;
  }
  TreeNode* deleteNode(TreeNode*root,int key){
    if(root==nullptr) return nullptr;
    if(root->val==key){
      //找到啦，进行删除
      if(root->left==nullptr) return root->right;
      if(root->right==nullptr) return root->left;
      TreeNode* minNode = getMin(root->right);
      root->val = minNode->val;
      root->right = deleteNode(root->right,minNode->val);
    }else if(root->val,key){
      root->left=deleteNode(root->left,key);
    }else{
      root->right = deleteNode(root->right,key);
    }
    return root;
  }
  TreeNode* getMin(TreeNode* node){
    while(node->left!=nullptr) node = node->left;
    return node;
  }
};
