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

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
      queue<TreeNode*> q;
      vector<int>ans;
      if(root!=nullptr) q.push(root);
      TreeNode* node;

      while(!q.empty()){
        int n=q.size();
        int MAX=INT_MIN;
         //把ans定义在while里使得每次进入循环能得到新的vector容器，如果在循环外定义在\
         进入下一次循环前得清空vector里的元素；
        //vector<int>ans;
        for(int i=0;i<n;i++)
        // 这⾥⼀定要使⽤固定⼤⼩size，不要使⽤que.size()，因为que.size是不断变化的
        {
          node=q.front();
          q.pop();
          MAX=max(MAX,node->val);
          if(node->left) q.push(node->left);
          if(node->right) q.push(node->right);
        }
        ans.push_back(MAX);
      }
      return ans;
    }
};
