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
class Solution{
public:
  bool isSameTree(TreeNode*tree1,TreeNode*tree2){
    if(tree1==nullptr&&tree2!=nullptr) return false;
    else if(tree1!=nullptr&&tree2==nullptr) return false;
    else if(tree1==nullptr&&tree2==nullptr) return true;
    else if(tree1->val!=tree2->val) return false;
    bool leftD=isSameTree(tree1->left,tree2->left);
    bool rightD=isSameTree(tree2->right,tree2->right);
    bool isSame=leftD&&rightD;
    return isSame;
  }
};
