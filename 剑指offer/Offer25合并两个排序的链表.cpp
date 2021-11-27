
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode* dummy=new ListNode(-1);
      ListNode* head=dummy;
      while(l1!=nullptr&&l2!=nullptr){
        if(l1->val<l2->val){
          dummy->next=l1;
          l1=l1->next;
        }else{
          dummy->next=l2;
          l2=l2->next;
        }
        dummy=dummy->next;
      }
      dummy->next=l1==nullptr?l2:l1;
      return head->next;
    }
    ListNode* mergeTwoLists_(ListNode* l1, ListNode* l2) {
     if(l1==nullptr) return l2;
     if(l2==nullptr) return l1;
     if(l1->val<=l2->val){
       l1->next=mergeTwoLists_(l1->next,l2);
       return l1;
     }else{
       l2->next=mergeTwoLists_(l1,l2->next);
       return l2;
     }
    }
};
