struct TreeNode{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};
class Solution{
public:
  bool judge(TreeNode*left,TreeNode*right)
  {
    if(left==nullptr&&right==nullptr) return true;
    if(left==nullptr||right==nullptr) return false;
    int leftVal=left->val;
    int rightVal=right->val;
    if(leftVal!=rightVal)return false;
    else{
      return judge(left->left,right->right)&&judge(left->right,right->left);
    }
  }

  bool isDC(TreeNode* root)
  {
    if(root==nullptr) return true;
    return judge(root->left,root->right);
  }
}
