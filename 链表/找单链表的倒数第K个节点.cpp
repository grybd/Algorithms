
#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int _val): val(_val),next(nullptr){}
};

class Solution{
public:
    ListNode* findNode(ListNode* head,int k){
      ListNode*cur=head,*prev=head;
      for(int i=0;i<k;i++){
        if(cur){
          cur = cur->next;
        }else{
          return nullptr;
        }
      }
      while(cur){
        prev = prev->next;
        cur = cur->next;
      }
      return prev;
    }
};
