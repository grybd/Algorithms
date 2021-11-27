#include <vector>
#include <stack>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
private:
  int maxCount;
  int count;
  TreeNode* pre;
  vector<int> res;
  void traversal(TreeNode*root){
    if(root==nullptr) return ;
    traversal(root->left);
    if(pre==nullptr) count++;
    else if(pre->val==root->val) count+=1;
    else count=1;
    if(count==maxCount) res.push_back(root->val);
    if(count>maxCount){
      maxCount=count;
      res.clear();
      res.push_back(root->val);
    }
    pre=root;
    traversal(root->right);
    return ;
  }
public:
    vector<int> findMode(TreeNode* root) {
      int maxCount=0;
      int count=0;
      TreeNode* pre=nullptr;
      traversal(root);
      return res;
    }
    //不是搜索二叉树的情况
    void searchBST(TreeNode*root,unordered_map<int,int>&map){
      if(root==nullptr) return;
      map[root->val]++;
      searchBST(root->left,map);
      searchBST(root->right,map);
      return ;
    }
    bool static cmp(const pair<int,int>&a,const pair<int,int>&b){
      return a.second>b.second;
    }
    vector<int> _findMode(TreeNode*root){
      unordered_map<int,int>map;
      vector<int>result;
      if(root==nullptr) return res;
      searchBST(root,map);
      vector<pair<int,int>>vec(map.begin(),map.end());
      sort(vec.begin(),vec.end(),cmp);
      res.push_back(vec[0].first);
      for(int i=1;i<(int)vec.size();i++){
        if(vec[i].second==vec[0].second) res.push_back(vec[i].first);
      }
      return res;
    }

    vector<int>result;
    void traversal_(TreeNode*root){
      if(root==nullptr) return;
      traversal_(root->left);
      result.push_back(root->val);
      traversal_(root->right);
    }
    vector<int> _findMode_(TreeNode*root){
      if(root==nullptr) return result;
      traversal_(root);
      int maxCount=1;

      int count=1;
      for(int i=1;i<(int)result.size();i++){
        if(result[i]==res[i-1]){
          count++;
        }
        else{
          if(count==maxCount) result.push_back(result[i-1]);
          if(count>maxCount){
            result.clear();
            maxCount=count;
            result.push_back(result[i-1]);
          }
          count=1;
        }
      }
      return result;
    }
};
