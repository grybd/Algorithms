#include <vector>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;

struct Node{
  int val;
 Node *left;
 Node *right;
 Node *next;
};

class Solution{
public:
  Node* connect(Node*root){
    queue<Node*> q;
    if(root!=nullptr) q.push(root);
    Node* node;
    while(!q.empty()){
      int n=q.size();
      vector<Node*>ans;
      //vector<int>ans;
      for(int i=0;i<n;i++)
      // 这⾥⼀定要使⽤固定⼤⼩size，不要使⽤que.size()，因为que.size是不断变化的
      {
        node=q.front();
        q.pop();
        ans.push_back(node);
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
      }

      for(int i=0;i<(int)ans.size();i++)
      {
        if(i+1<(int)ans.size())
        {
            ans[i]->next=ans[i+1];
        }
        else{
            ans[i]->next=nullptr;
        }
      }
    }
    return root;
  }
};
