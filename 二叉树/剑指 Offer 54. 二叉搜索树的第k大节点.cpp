  struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
class Solution {
public:
    int count=0,res=0;
    int kthLargest(TreeNode* root, int k) {
        inorder(root,k);
        return res;
    }
    void inorder(TreeNode* root,int k){
      if(!root) return;
      inorder(root->right,k);
      count++;
      if(count==k) {
        res = root->val;
        return;
      }
      inorder(root->left,k);
    }
};
