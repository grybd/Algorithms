class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node() {}
    Node(int _val){
        val = _val;
        left = nullptr;
        right = nullptr;
    }
    Node(int _val,Node* _left,Node* _right){
        val = _val;
        left = _left;
        right = _right;
    }
};
class Solution {
public:
    Node* head=nullptr;
    Node* tail=nullptr;
    Node* treeToDoublyList(Node* root) {
      if(root==nullptr) return root;
      Node* leftN = treeToDoublyList(root->left);
      if(!tail) head = leftN;
      else{
        tail->right = leftN;
        leftN->left = tail;
      }
      tail=leftN;
      Node* rightN = treeToDoublyList(root->right);
      head->left = tail;
      tail->right = head;
      return head;
    }
};
