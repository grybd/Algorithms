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
  ListNode* oddEvenList(ListNode*head){
    if(head==nullptr||head->next==nullptr) return head;
    ListNode* f_head=head,*j_head=head->next;
    while(j_head!=nullptr&&j_head->next!=nullptr){
      ListNode*temp=f_head->next;
      f_head->next=j_head->next;
      j_head->next=j_head->next->next;
      f_head->next->next=temp;
      f_head=f_head->next;
      j_head=j_head->next;
    }
    return head;
  }
};
