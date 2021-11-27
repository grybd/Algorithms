#include <bits/stdc++.h>
using namespace std;

  struct TreeNode {
 	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回二叉树上最长01相间路径长度
     * @param root TreeNode类
     * @return int整型
     */
    int depth(TreeNode*root){
      if (root==nullptr) return 0;
      int leftD = depth(root->left);
      int rightD = depth(root->right);
      return max(leftD,rightD)+1;
    }
    int longest01Path(TreeNode* root) {
        // write code here
        if(root==nullptr) return 0;
        int leftD = longest01Path(root->left);
        int rightD = longest01Path(root->right);
        return leftD+rightD+1;
    }
};
