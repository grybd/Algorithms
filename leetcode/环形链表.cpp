#include <unordered_set>
using namespace std;
struct ListNode{
  int val;
  ListNode*next;
} ;
//哈希表法；
/*
class Solution{
public:
  bool hasCycle(ListNode*head)
  {
    unordered_set<ListNode*>seen;
    while(head!=nullptr)
    {
      if(seen.count(head))
      return true;

      seen.insert(head);
      head=head->next;
    }
    return false;
  }
};*/
//快慢指针
class Solution{
public:
  bool hasCycle(ListNode*head)
  {
    if(head==nullptr||head->next==nullptr)
    return false;
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(slow!=fast)
    {
      if(fast==nullptr||fast->next==nullptr)
      return false;
      slow=slow->next;
      fast=fast->next->next;
    }
  }
};
