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
  //双指针
  ListNode* middleNode(ListNode* head) {
    ListNode*last=head,*fast=head;
    while(fast!=nullptr&&fast->next!=nullptr)
    {
      last=last->next;
      fast=fast->next->next;
    }
    return last;
  }
  ListNode* _middleNode(ListNode* head) {
    vector<ListNode*> vec;
    while(head){
      vec.push_back(head);
      head=head->next;
    }
    return vec[vec.size()/2];
  }
  ListNode* _middleNode_(ListNode* head) {
    if(!head) return head;
    int len=0;
    while(head){
      len++;
      head=head->next;
    }
    int n=len/2;
    while(n){
      head=head->next;
      n--;
    }
    return head;
  }

};
