#include <vector>
using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution{
public:
  vector<vector<int>>res;
  vector<int> ans;
  vector<vector<int>>pathSum(TreeNode* root,int sum)
  {
    if(root==nullptr)
    return res;
    dfs(root,sum);
    return res;
  }
  void dfs(TreeNode* root,int sum)
  {
    if(root==nullptr)
    return;
    ans.push_back(root->val);
    sum-=root->val;
    if(root->left==nullptr&&root->right==nullptr&&sum==0)
    {
      res.push_back(ans);
    }
    dfs(root->left,sum);
    dfs(root->right,sum);
    ans.pop_back();
  }
};
