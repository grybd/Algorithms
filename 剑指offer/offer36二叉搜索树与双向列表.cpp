
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
     Node* treeToDoublyList(Node* root){
       if(root==nullptr) return nullptr;
       dfs(root);
       head->left=tail;
       tail->right=head;
       return head;
     }
private:
    Node* head,*tail;
    void dfs(Node* cur){
      if(cur==nullptr) return;
      dfs(cur->left);
      if(tail!=nullptr) tail->right=cur;
      else head = cur;
      cur->left=tail;
      tail = cur;
      dfs(cur->right);
    }
  };
