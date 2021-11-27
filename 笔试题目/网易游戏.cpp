#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
     int value;
     Node* left;
     Node* right;
     Node(int data){
        this->value = data;
    }
};

 class Solution {
      Node* bstNode = nullptr;
      int max_ = INT_MIN;
      Node* pre = nullptr;
    public:
        int getMaxBST(Node*root){
        if(root == nullptr)
            return 0;
        getMaxroot(root);
        return max_;
    }
    void getMaxroot(Node*root){
      pre = nullptr;
      if(isBST(root)){
          int nodesNum = getNodesNum(root);
          if(nodesNum > max_){
              max_ = nodesNum;
              bstNode = root;
          }
      }
      getMaxroot(root->left);
      getMaxroot(root->right);
    }
    //获得二叉树节点个数
    int getNodesNum(Node*root){
        if(root == nullptr)
            return 0;
        return 1 + getNodesNum(root->left) + getNodesNum(root->right);
    }
    //判断是否是一颗搜索二叉树 中序遍历 左中右
     bool isBST(Node* root){
        if(root == nullptr)
            return true;
        bool left_ = isBST(root->left);
        if(pre&&pre->value>=root->value) return false;
        pre = root;
        bool right_ = isBST(root->right);
        return left_&&right_;
    }
  };
int main(){
    int n, rootVal;
    int line[3];
    TreeNode* root = nullptr;
    unordered_map<int, TreeNode*> treeNodes;
    treeNodes.insert(make_pair(0, nullptr));
    cin >> n >> rootVal;
    while(n--){
        cin >> line[0] >> line[1] >> line[2];
        for(int i = 0; i < 3; i++){
            if(treeNodes.count(line[i]) == 0){
                treeNodes.insert(make_pair(line[i], new TreeNode(line[i])));
            }
        }
        treeNodes[line[0]]->left = treeNodes[line[1]];
        treeNodes[line[0]]->right = treeNodes[line[2]];
    }
    root = treeNodes[rootVal];
    cout << Solution::getMaxBSTree(root).first;
    return 0;
}
