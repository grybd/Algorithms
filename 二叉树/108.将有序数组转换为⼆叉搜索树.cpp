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

class Solution{
    private:
       TreeNode* traversal(vector<int>&nums,int left,int right){
           if(left>right) return nullptr;
           int mid=left+(right-left)/2;
           TreeNode* root=new TreeNode(nums[mid]);
           root->left=traversal(nums,left,mid-1);
           root->right=traversal(nums,mid+1,right);
           return root;
       }
    public:
       TreeNode* sortedArrayToBST(vector<int>&nums){
           TreeNode* root=traversal(nums,0,nums.size()-1);
           return root;
       }
      };

   int main(){
       Solution s;
       vector<int> res={-10,-3,0,5,9};
       s.sortedArrayToBST(res);
       return 0;
   }
