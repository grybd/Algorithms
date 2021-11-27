#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution{
public:
  vector<vector<int>>ans;
  queue<TreeNode*> q;
  vector<vector<int>> levelOrder(TreeNode*root)
  {
    if(root==nullptr)
    return{};
    q.push(root);
    while(!q.empty())
    {
      vector<int>tem;
      int n=q.size();

      for(int i=0;i<n;i++)
      {
        TreeNode* node=q.front();
        tem.push_back(node->val);
        q.pop();

        if(node->left!=nullptr)
        {
          q.push(node->left);
        }
        if(node->right!=nullptr)
        {
          q.push(node->right);
        }
      }
      ans.push_back(tem);
    }
    return ans;
  }
};
