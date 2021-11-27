#include <iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int _val): val(_val),next(nullptr){}
};

class Solution {
public:
  //递归方法反转链表；
  ListNode* reverseListNode(ListNode*&head){
    if(!head) return nullptr;
    if(head->next==nullptr) return head;
    ListNode* ret=reverseListNode(head->next);
    head->next->next=head;
    head->next=nullptr;
    return ret;
  }
  //迭代法反转链表
  ListNode* _reverseListNode(ListNode*&head)
  {
    if(!head||!head->next){
      return head;
    }
    ListNode* prev=nullptr;
    ListNode* cur = head;
    while(cur){
      ListNode* dummy = cur->next;
      cur->next = prev;
      prev = cur;
      cur = dummy;
    }
    return prev;
  }
};
