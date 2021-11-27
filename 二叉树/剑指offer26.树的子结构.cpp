#include <vector>
#include <stack>
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode{
  char val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    //树的子结构
    bool isSubStructure(TreeNode* A, TreeNode* B) {
      if(A==nullptr||B==nullptr) return false;
      return recur(A,B)||isSubStructure(A->left,B)||isSubStructure(A->right,B);
    }
    bool recur(TreeNode*A, TreeNode* B){
      if(B==nullptr) return true;
      if(A==nullptr||A->val!=B->val) return false;
      return recur(A->left,B->left)&&recur(A->right,B->right);
    }
    //树的子树

};
