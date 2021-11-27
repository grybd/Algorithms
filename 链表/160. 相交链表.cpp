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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      if(headA==nullptr||headB==nullptr) return nullptr;
      if(headA==headB) return headB;
      ListNode*pA=headA,*pB=headB;

      while(pA!=pB)
      {
       pA=pA==nullptr?headB:pA->next;
       pB=pB==nullptr?headA:pB->next;
      }
    return pA;
    }
};
