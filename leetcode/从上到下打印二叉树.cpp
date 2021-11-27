#include <vector>
#include <queue>
using namespace std;
struct TreeNode{
  int val;
  TreeNode*left;
  TreeNode*right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution{
public:
  vector<int>levelOrfer(TreeNode* root)
  {
    if(root == nullptr)
    return {};
    vector<int>res;
    queue<TreeNode*> bfs;
    bfs.push(root);
    while(!bfs.empty())
    {
      TreeNode*temp=bfs.front();
      res.push_back(bfs.front()->val);
      bfs.pop();
      if(temp->left) bfs.push(temp->left);
      if(temp->right) bfs.push(temp->right);
    }
    return res;
  }
};
