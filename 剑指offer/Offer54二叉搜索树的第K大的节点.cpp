#include <vector>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      };
class Solution {
public:
    //先中序遍历在求第k大的数
   int kthLargest_(TreeNode* root, int k) {
       vector<int>res;
       dfs(root,k,res);
       return res[res.size()-k];
   }
   void dfs(TreeNode* root,int k,vector<int>&res){
       if(root==nullptr) return ;
       dfs(root->left,k,res);
       res.push_back(root->val);
       dfs(root->right,k,res);
   }
 private:
    int count=0,res=0;
 public:
    int kthLargest(TreeNode* root, int k) {
        inorder(root,k);
        return res;
    }
    void inorder(TreeNode*root,int k){
      if(root==nullptr) return;
      inorder(root->right,k);
      ++count;
      if(count==k) {
        res=root->val;
        return;
      }
      inorder(root->left,k);
    }
};
