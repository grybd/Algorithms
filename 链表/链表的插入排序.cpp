#include <bits/stdc++.h>
using namespace std;

struct ListNode{
  int val;
  ListNode*next;
  ListNode(int x):val(x),next(nullptr){}
};

class Solution{
public:
  ListNode* insertionSortList(ListNode*head){
    if(!head||!head->next) return head;
    ListNode* dummy = new ListNode(INT_MIN);
    dummy->next = head;
    ListNode* tail=head,*sort = head->next;
    while(sort){
      if(sort->val<tail->val){
        ListNode* pos = dummy;
        while(pos->next->val<sort->val) {pos = pos->next;}
        tail->next = sort->next;
        sort->next = pos->next;
        pos->next = sort;
        sort = tail->next;
      }else{
        sort = sort->next;
        tail = tail->next;
      }
    }
    ListNode* tmp = dummy->next;
    delete dummy;
    return tmp;
  }
};
