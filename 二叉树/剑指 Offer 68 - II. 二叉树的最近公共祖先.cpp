#include <queue>
#include <vector>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
      if(!root||!p||!q||p==root||q==root) return root;

      vector<TreeNode*>pPath;
      vector<TreeNode*>qPath;

      getNodePath(root,p,pPath);
      getNodePath(root,q,qPath);

      return getlowestCommonAncestor(pPath,qPath);
    }
    void getNodePath(TreeNode*root,TreeNode*node,vector<TreeNode*>&path){
      if(!root||!node) return ;
      deque<TreeNode*>store;
      TreeNode* tmp=root,*prev=nullptr;
      while(tmp||!store.empty()){
        while(tmp){
          store.push_back(tmp);
          if(node==tmp){
            while(!store.empty()){
              TreeNode* t = store.front();
              store.pop_front();
              path.push_back(t);
            }
            return ;
          }
          tmp=tmp->left;
        }
        tmp = store.back();
        if(!tmp->right||tmp->right==prev){
          store.pop_back();
          prev=tmp;
          tmp=nullptr;
        }else{
          tmp=tmp->right;
        }
      }
    }
    TreeNode* getlowestCommonAncestor(vector<TreeNode*>&pPath,vector<TreeNode*>&qPath){
      if(pPath.empty()||qPath.empty()) return nullptr;
      int size = min(pPath.size(),qPath.size());
      int i=0;
      for(;i<size;i++){
        if(pPath[i]==qPath[i]){
          continue;
        }
        else {
          break;
        }
      }
      return pPath[i-1];
    }
};
