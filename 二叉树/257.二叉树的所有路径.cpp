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
    private:
      void traversal(TreeNode*cur,vector<int>&path,vector<string>&res)
      {
        path.push_back(cur->val);
        if(cur->left==nullptr&&cur->right==nullptr){
          string spath;
          for(int i=0;i<(int)path.size()-1;i++){
            spath+=to_string(path[i]);
            spath+="->";
          }
          spath+=to_string(path.size()-1);
          res.push_back(spath);
          return;
        }
        if(cur->left){
          traversal(cur->left,path,res);
          path.pop_back();
        }
        if(cur->right){
          traversal(cur->right,path,res);
          path.pop_back();
        }

      }
    public:
        vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        vector<int>path;
        if(root == nullptr) return res;
        traversal(root,path,res);
        return res;
      }
};
