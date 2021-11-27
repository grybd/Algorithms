#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode{
  int val;
  TreeNode*left;
  TreeNode*right;
  TreeNode(int x):val(x), left(nullptr),right(nullptr){}
};
class Solution{
private:
   unordered_map<int,int> index;
public:
   TreeNode*mytree(const vector<int>&preorder,const vector<int>&inorder,int preorderL,int preorderR,int inorderL,int inorderR)
   {
     if(preorderL>preorderR||inorderL>inorderR)
     {
       return nullptr;
     }

     int preorder_root=preorderL;
     int inorder_root=index[preorder[preorder_root]];
     int left_subtree_num=inorder_root-inorderL;
     TreeNode* root=new TreeNode(preorder[preorder_root]);

     root->left=mytree(preorder,inorder,preorderL+1,preorderL+left_subtree_num,inorderL,inorder_root-1);
     root->right=mytree(preorder,inorder,preorderL+left_subtree_num+1,preorderR,inorder_root+1,inorderR);
     return root;
   }
   TreeNode*buildTree(vector<int>&preorder,vector<int>&inorder)
   {
     int n=inorder.size();
     for(int i=0;i<n;i++)
     {
       index[inorder[i]]=i;
     }
     return mytree(preorder,inorder,0,n-1,0,n-1);
   }
};
