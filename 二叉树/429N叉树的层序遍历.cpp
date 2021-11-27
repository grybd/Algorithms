#include <vector>
#include <stack>
#include <iostream>
#include <queue>
using namespace std;

class Node{
public:
  int val;
  vector<Node*>children;
  Node(){};
  Node(int _val){
    val=_val;
  }
  Node(int _val,vector<Node*>_children){
    val=_val;
    children=_children;
  }
};

class Solution{
public:
  vector<vector<int>> levelOrder(Node* root) {
    queue<Node*> q;
    if(root!=nullptr) q.push(root);
    vector<vector<int>>res;
    Node* node;
    while(!q.empty()){
      vector<int>ans;
      int n=q.size();
      for(int i=0;i<n;i++){
        node=q.front();
        q.pop();
        ans.push_back(node->val);
        for(int i=0;i<(int)node->children.size();i++)
        {
          q.push(node->children[i]);
        }
      }
      res.push_back(ans);
    }
    return res;
  }

};
