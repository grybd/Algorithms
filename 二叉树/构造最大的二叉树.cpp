#include <vector>
#include <stack>
#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

struct TreeNode{
  char val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return nullptr;
        return dfs(nums,0,nums.size()-1);
    }

    TreeNode*dfs(vector<int>&nums,int start,int end){
        if(end<start) return nullptr;
        int min=INT_MIN;
        int index=start;
        for(int i=start;i<=end;i++)
        {
            if(nums[i]>min){
                min=nums[i];
                index=i;
            }
        }
        TreeNode*root=new TreeNode(nums[index]);
        root->left=dfs(nums,start,index-1);
        root->right=dfs(nums,index+1,end);
        return root;
    }
};
