#include <stack>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode():val(0),next(nullptr){}
  ListNode(int x):val(x),next(nullptr){}
  ListNode(int x,ListNode*next):val(x),next(next){}
};

class Solution {
public:
    //递归
    ListNode* deleteDuplicates(ListNode* head) {
      if(!head||!head->next) return head;
      if(head->val!=head->next->val){
        head->next = deleteDuplicates(head->next);
      }else{
        ListNode* move = head->next;
        while(move && head->val==move->val){
          move = move->next;
        }
        return deleteDuplicates(move);
      }
      return head;
    }
    //迭代
    ListNode* deleteDuplicates_(ListNode* head){
      if(!head||!head->next) return head;
      ListNode*preHead = new ListNode(0);
      preHead->next=head;
      ListNode* pre = preHead;
      ListNode* cur = head;
      while(cur){
        while(cur->next&&cur->val==cur->next->val){
          cur=cur->next;
        }
        if(pre->next==cur){
          pre = pre->next;
        }else{
          pre->next=cur->next;
        }
        cur = cur->next;
      }
      return preHead->next;
    }
};
