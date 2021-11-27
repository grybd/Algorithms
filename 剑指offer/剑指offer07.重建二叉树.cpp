#include <vector>
#include <unordered_map>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    unordered_map<int,int>map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      for(int i=0;i<(int)inorder.size();i++){
        map[inorder[i]]=i;
      }
      TreeNode*root = build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
      return root;
    }
    TreeNode* build(vector<int>&preorder,vector<int>&inorder,int pre_start,int pre_end,int in_start,int in_end){
      if(pre_start>pre_end||in_start>in_end) return nullptr;
      TreeNode* root = new TreeNode(preorder[pre_start]);
      int in_mid = map[preorder[pre_start]];
      int temp = in_mid+pre_start-in_start;
      root->left=build(preorder,inorder,pre_start+1,temp,in_start,in_mid-1);
      root->right=build(preorder,inorder,temp+1,pre_end,in_mid+1,in_end);
      return root;
    }
};
