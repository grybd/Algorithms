#include <vector>
#include <stack>
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==nullptr) return nullptr;
        if(root->val<low){
            TreeNode* right=trimBST(root->right,low,high);
            return right;
        }
        if(root->val>high){
            TreeNode* left=trimBST(root->left,low,high);
            return left;
        }
        root->left=trimBST(root->left,low,high);
        root->right=trimBST(root->right,low,high);
        return root;
    }
};
