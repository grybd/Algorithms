struct ListNode{
  int val;
  ListNode* next;
  ListNode():val(0),next(nullptr){}
  ListNode(int x):val(x),next(nullptr){}
  ListNode(int x,ListNode*next):val(x),next(next){}
};

class Solution{
public:
  //迭代法
  ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
    if(!l1) return l2;
    if(!l2) return l1;
    ListNode* dummy = new ListNode(-1);
    ListNode* prev = dummy;
    while(l1&&l2){
      if(l1->val<l2->val){
        prev->next = l1;
        l1 = l1->next;
      }else{
        prev->next = l2;
        l2 = l2->next;
      }
      prev = prev->next;
    }
    if(!l1) prev->next = l2;
    if(!l2) prev->next = l1;
    ListNode* p = dummy->next;
    delete dummy;
    return p;
  }
  //递归
  ListNode* mergeTwoLists_(ListNode* l1,ListNode* l2){
    if(!l1) return l2;
    if(!l2) return l1;

  }
};
