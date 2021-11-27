#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode():val(0),left(nullptr),right(nullptr){}
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
  TreeNode(int x,TreeNode *left,TreeNode *right):val(x),left(left),right(right){}
};

class Solution{
public:
  unordered_map<TreeNode*,int> memo;
  int rob(TreeNode* root){

    if(root==nullptr) return 0;

    if(memo.count(root)) return memo[root];

    int rob_it=root->val+(root->left==nullptr?0:rob(root->left->left)+rob(root->left->right))+\

    +(root->right==nullptr?0:rob(root->right->left)+rob(root->right->right));

    int not_rob = rob(root->left)+rob(root->right);

    int res=max(rob_it,not_rob);

    memo[root]=res;

    return res;

  }
};
