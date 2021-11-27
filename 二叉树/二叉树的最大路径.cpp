#include <limits.h>
#include <algorithm>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    int max1=INT_MIN;
    int maxPathSum(TreeNode* root) {
      helper(root);
      return max1;
    }
    int helper(TreeNode* root){
      if(root==nullptr) return 0;
      int left=max(helper(root->left),0);
      int right=max(helper(root->right),0);
      max1=max(max1,root->val+left+right);
      return root->val+max(left,right);
    }
};
