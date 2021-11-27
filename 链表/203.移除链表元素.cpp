#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int _val): val(_val),next(nullptr){}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
      //删除头结点
      while(head!=nullptr&&head->val==val){
        ListNode* temp=head;
        head=head->next;
        delete temp;
      }
      //删除非头节点
      ListNode* cur=head;
      while(cur!=nullptr&&cur->next!=nullptr){
        if(cur->next->val==val){
          ListNode* temp=cur->next;
          cur->next=cur->next->next;
          delete temp;
        }else{
          cur=cur->next;
        }
      }
      return head;
    }
    ListNode* _removeElements(ListNode* head, int val){
      ListNode* dummy=new ListNode(-1);
      ListNode* cur;
      dummy->next=head;
      cur=dummy;
      while(cur->next!=nullptr){
        if(cur->next->val==val){
          ListNode* temp=cur->next;
          cur->next=cur->next->next;
          delete temp;
        }
        else cur=cur->next;
      }
      head=dummy->next;
      delete dummy;
      return head;
    }
};
