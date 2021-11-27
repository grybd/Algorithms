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
  bool hasCycle(ListNode*head)
  {
    if(head==nullptr) return false;
    ListNode* ptr=head,*ptem=head->next;
    while(ptem!=nullptr&&ptem->next!=nullptr)
    {
      if(ptr==ptem) {
        return true;
      }
      ptr=ptr->next;
      ptem=ptem->next->next;
    }
    return false;
  }
};
