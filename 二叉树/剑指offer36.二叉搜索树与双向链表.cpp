
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node() {}
    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }
    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
      if(root == nullptr) return nullptr;
      dfs(root);
      head->left = prev;
      prev->right = head;
      return head;
    }
private:
  Node *prev,*head;
  void dfs(Node* root){
    if(root==nullptr) return;
    dfs(root->left);
    if(!prev) prev = head;
    else {
      prev->right = root;
      root->left = prev;
    }
    prev = root;
    dfs(root->right);
    }
    Node* treeToDoublyList_(Node* root) {
      if(root == nullptr) return nullptr;
      dfs(root);
      head->left = prev;
      prev->right = head;
      return head;
    }


};
