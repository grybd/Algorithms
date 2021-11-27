#include <unordered_set>
using namespace std;
struct ListNode{
  int val;
  ListNode*next;
};
class Solution{
public:
  ListNode*getIntersectionNode(ListNode*headA,ListNode*headB)
  {
    unordered_set<ListNode*>set;
    ListNode*cur_a=headA;
    while(cur_a)
    {
      set.insert(cur_a);
      cur_a=cur_a->next;
    }

    ListNode*cur_b=headB;
    while(cur_b)
    {
      if(set.find(cur_b)!=set.end())
      {
        return cur_b;
      }
      cur_b=cur_b->next;
    }
    return nullptr;
  }
};
