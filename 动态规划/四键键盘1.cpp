#include <bits/stdc++.h>
using namespace std;

struct Node{
  int val;
  Node* cur;
  Node* left;
  Node* up;
  Node* right;
  Node* down;
  Node(int _val):val(_val),cur(nullptr),left(nullptr),up(nullptr),right(nullptr),down(nullptr){}
};

Node* CreateMap(Node*root){
  return root;
}
int main(){
  unordered_map<int,Node*>map;
   int N;
   int M;
   cin>>N>>M;
   int sum=N*M;
   while(sum--){
     vector<Node*>ans;
     int i;
     int l,u,r,d;
     cin>>i>>l>>u>>r>>d;
     Node* root=new Node(i);
     Node* rl=nullptr,*ru=nullptr,*rr=nullptr,*rd=nullptr;
     if(l!=0)
     rl = new Node(l);
     if(u!=0)
      ru = new Node(u);
     if(r!=0)
     rr = new Node(r);
     if(d!=0)
     rd = new Node(d);
     root->left = rl;
     root->up = ru;
     root->right = rr;
     root->down = rd;
     map[i] = root;
   }
    Node* need=nullptr;
   for(auto it:map){
     if(it.second->left==nullptr&&it.second->up==nullptr){
       need = it.second;
     }
   }
   auto r = need;
   auto d = need;
   while(d){
     r = d;
     while(!r){
        cout<<need->val<< " ";
        need = need->right;
     }
     cout<<endl;
     d = d->down;
   }
   }
