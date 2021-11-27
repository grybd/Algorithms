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
  ListNode* detectCycle(ListNode* head){
    ListNode* fast=head,*slow=head;
    while(fast&&fast->next){
      slow = slow->next;
      fast = fast->next->next;
      if(slow==fast) break;
    }
    if(!fast||!fast->next){
      return nullptr;
    }
    slow = head;
    while(slow!=fast){
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
};
