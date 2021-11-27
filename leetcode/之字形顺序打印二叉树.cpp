#include <vector>
#include <deque>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
      if(!root) return {};

    vector<vector<int>>res;
    deque<TreeNode*>que;
    que.push_back(root);
    bool flag=true;
    while(!que.empty())
    {
      int cnt=que.size();
      vector<int>level;
      while(cnt>0)
      {
        if(flag)
        {
          auto node=que.front();
          level.push_back(node->val);
          que.pop_front();
          if(node->left) que.push_back(node->left);
          if(node->right) que.push_back(node->right);
        }
        else{
          auto node=que.back();
          level.push_back(node->val);
          que.pop_back();
          if(node->right) que.push_front(node->right);
          if(node->left) que.push_front(node->left);
        }
        cnt--;
      }
      res.push_back(level);
      flag=!flag;
    }
    return res;
    }
};
