#include <vector>
#include <string>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:
  string serialize(TreeNode* root){
    string res;
    if(root==nullptr) return "";
    queue<TreeNode*>my_queue;
    my_queue.push(root);
    TreeNode* cur = new TreeNode(0);
    while(!my_queue.empty()){
      int len = my_queue.size();
      while(len--){
        cur = my_queue.front();
        my_queue.pop();
        if(cur==nullptr) res.push_back('@');
        else{
          res.append(to_string(cur->val));
        }
        res.push_back(',');
        if(cur!=nullptr){
          my_queue.push(cur->left);
          my_queue.push(cur->right);
        }
      }
    }
    res.pop_back();
    return res;
  }

  TreeNode* deserialize(string data){
    if(data.size()==0) return nullptr;
    int len = data.size();
    int i=0,j=0;
    string str="";
    while(i<len){
      if(data[i]!=','){
        str+=data[i];
        i++;
      }else i++;
    }
  vector<TreeNode*>vec;
  while(j<(int)str.size()){
    if(str[j]=='@'){
      TreeNode* temp=nullptr;
      vec.push_back(temp);
    }else{
      int temp = str[j]-'0';
      TreeNode*cur = new TreeNode(temp);
      vec.push_back(cur);
    }
    j++;
  }
  //遍历vec,构建二叉树的结构
  int k=1;
  for(int i=0;i<(int)vec.size();i++){
    if(vec[i]==nullptr) continue;
    if(k<(int)vec.size()) vec[i]->left = vec[j++];
    if(k<(int)vec.size()) vec[i]->right = vec[j++];
  }
  return vec[0];
}
};
