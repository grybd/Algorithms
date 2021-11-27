#include <bits/stdc++.h>
using namespace std;


class ListNode{
public:
  ListNode(int val_):val(val_),next(nullptr){}
  ListNode* next;
  int val;
}

class Solution{
     public:
       //自顶xiang'xia
       ListNode* sortList(ListNode*head){
         if(head==nullptr||head->next==nullptr) return head;
         ListNode* fast = head->next,*slow = head;
         while(fast!=nullptr&&fast->next!=nullptr){
           slow = slow->next;
           fast = fast->next->next;
         }
         ListNode* tmp = slow->next;
         slow->next = nullptr;
         ListNode* left = sortList(head);
         ListNode* right = sortList(tmp);
         return mergeListNode(left,right);
       }

       ListNode*mergeListNode(ListNode*left,ListNode*right){
         ListNode* dummy = new ListNode(0);
         ListNode* res = dummy;
         while(left!=nullptr&&right!=nullptr){
           if(left->val<right->val){
             dummy->next = left;
             left = left->next;
           }else{
             dummy->next = right;
             right = right->next;
           }
           dummy = dummy->next;
         }
         if(left==nullptr) dummy->next = right;
         else dummy->next = left;
         return res->next;
       }
 };
