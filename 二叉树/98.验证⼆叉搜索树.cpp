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

class Solution{
  private:
    vector<int>res;
  void traversal(TreeNode*root){
    if(root==nullptr) return;
    traversal(root->left);
    res.push_back(root->val);
    traversal(root->right);
  }
  public:
    bool isValidBST(TreeNode*root){
      res.clear();
      traversal(root);
      for(int i=1;i<(int)res.size();i++){
        if(res[i]<=res[i-1]) return false;
      }
      return true;
    }
    long long maxVal=LONG_MIN;
    bool _isValidBST(TreeNode* root){
      if(root==nullptr) return true;
      bool left=_isValidBST(root->left);
      if(maxVal<root->val) maxVal=root->val;
      else return false;
      bool right=_isValidBST(root->right);
      return left&&right;
    }
};

int main(){

  TreeNode* root=new TreeNode(5);
  TreeNode* a=new TreeNode(2);
  TreeNode* b=new TreeNode(3);
  TreeNode* c=new TreeNode(4);
  TreeNode* d=new TreeNode(6);
  TreeNode* e=new TreeNode(7);
  TreeNode* f=new TreeNode(8);

  root->left=b;
  b->left=a;
  b->right=c;

  root->right=e;
  e->left=d;
  e->right=f;
  Solution s;
  cout<<s._isValidBST(root);
}
