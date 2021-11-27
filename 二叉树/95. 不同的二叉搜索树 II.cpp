#include <vector>
#include <stack>
#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
  vector<TreeNode*>generateTrees(int start,int end){
    if(start>end){
      return {nullptr};
    }
    vector<TreeNode*>allTrees;
    //枚举可行根节点
    for(int i=start;i<=end;i++){
      //获得所有可行的左子树集合
      vector<TreeNode*>leftTrees = generateTrees(start,i-1);
      //获得所有可行的右子树集合
      vector<TreeNode*>rightTrees = generateTrees(i+1,end);
      for(auto&left:leftTrees){
        for(auto&right:rightTrees){
          TreeNode* currTree = new TreeNode(i);
          currTree->left = left;
          currTree->right = right;
          allTrees.push_back(currTree);
        }
      }
    }
    return allTrees;
  }
  vector<TreeNode*>generateTrees(int n){
    if(!n) return {};
    return generateTrees(1,n);
  }
};
