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
  ListNode* middleNode(ListNode* head){
    ListNode* slow = head,*fast = head;
    while(fast&&fast->next){
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};
