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
  ListNode *detectCycle(ListNode* head){
     if(!head) return head;
     ListNode* last=head,*fast=head;
     while(fast!=nullptr&&fast->next!=nullptr)
     {
       last=last->next;
       fast=fast->next->next;
       if(last==fast) {
           fast=head;
           while(fast!=last){
               fast=fast->next;
               last=last->next;
           }
           return last;
       }
     }
     return nullptr;
  }
};
