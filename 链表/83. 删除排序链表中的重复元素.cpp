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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* i_head=head,*j_head=head;

        while(j_head!=nullptr){
            while(j_head!=nullptr&&i_head->val==j_head->val){
                j_head=j_head->next;
            }
            if(j_head==nullptr) i_head->next=nullptr;
            else{
                  i_head->next=j_head;
                  i_head=j_head;
                  j_head=j_head->next;
            }
        }
        return head;
    }
};
