//Definition for a Node.
class Node{
public:
  int val;
  Node* left;
  Node* right;
  Node(){}
  Node(int _val){
    val = _val;
    left=nullptr;
    right=nullptr;
  }
  Node(int _val,Node* left,Node* right)
  {
    val = _val;
    left = left;
    right=right;
  }
};
class Solution{
  Node*pre,*head;
public:
  Node*treeToDoublyList(Node*root)
  {
    if(root==nullptr) return nullptr;
    dfs(root);
    head->left=pre;
    pre->right=head;
    return head;
  }

  void dfs(Node* cur)
  {
    if(cur==nullptr) return;
    dfs(cur->left);
    if(pre==nullptr) head=cur;
    else pre->right=cur;
    cur->left=pre;
    pre=cur;
    dfs(cur->right);
  }
};
