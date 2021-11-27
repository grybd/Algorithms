#include <vector>
#include <stack>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode{
  char val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    unordered_map<int,int>map;
    TreeNode* buildTree(vector<int>&inorder, vector<int>&postorder) {
        int n=inorder.size();int m=postorder.size();
        for(int i=0;i<n;i++){
            map[inorder[i]]=i;
        }
        if(inorder.size()==0||postorder.size()==0) return nullptr;
        return dfs(inorder,postorder,0,n-1,0,m-1);
    }
    TreeNode*dfs(vector<int>&inorder,vector<int>&postorder,int i_start,int p_start,int i_end,int p_end){
        if(i_start>i_end||p_start>p_end) return nullptr;
        int i_root_index=map[postorder[p_end]];
        TreeNode*root=new TreeNode(inorder[i_root_index]);
        root->left = dfs(inorder,postorder,i_start,p_start,i_root_index-1,p_end-i_end+i_root_index);
        root->right = dfs(inorder,postorder,i_root_index+1,p_end-i_end+i_root_index,i_end,p_end-1);
        return root;
    }
};
