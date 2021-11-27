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

class Solution{
public:
  vector<vector<int>> levelOrder(TreeNode*root){
    queue<TreeNode*> q;
    vector<vector<int>>res;
    vector<int>ans;
    if(root!=nullptr) q.push(root);
    TreeNode* node;
    while(!q.empty()){
      int n=q.size();
       //把ans定义在while里使得每次进入循环能得到新的vector容器，如果在循环外定义在\
       进入下一次循环前得清空vector里的元素；
      //vector<int>ans;
      for(int i=0;i<n;i++)
      // 这⾥⼀定要使⽤固定⼤⼩size，不要使⽤que.size()，因为que.size是不断变化的
      {
        node=q.front();
        q.pop();
        ans.push_back(node->val);
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
      }
      res.push_back(ans);
      ans.clear();
    }
    return res;
  }
};

int main(){
  TreeNode *root = new TreeNode(1);
  TreeNode *a = new TreeNode(2);
  TreeNode *b=new TreeNode(3);
  TreeNode *c=new TreeNode(4);
  TreeNode *d=new TreeNode(5);
  root->left=a;
  root->right=b;
  a->left=c;
  a->right=d;
  Solution s;
  vector<vector<int>>res=s.levelOrder(root);
  cout<<res[1].size();
  for(int i=0;i<(int)res[1].size();i++)
  {
    cout<<res[1][i]<<" ";
  }
}
