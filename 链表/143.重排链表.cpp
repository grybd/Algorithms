
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    void reorderList(ListNode* head) {
      if(head==nullptr) return;
      //找中间节点
      ListNode* mid = findMid(head);
      //获得中间节点之后的部分反转
      ListNode* head2 = mid->next;
      mid->next = nullptr;
      head2 = reverseList(head2);
      //合并
      ListNode* head1 = head;
      mergeList(head1,head2);
    }
private:
    ListNode* findMid(ListNode* head){
      if(!head||!head->next) return head;
      ListNode* slow=head,*fast=head;
      while(fast&&fast->next){
        slow = slow->next;
        fast = fast->next->next;
      }
      return slow;
    }
   ListNode* reverseList(ListNode* head){
     if(!head||!head->next) return head;
     ListNode* pre = head,*cur=head->next;
     while(cur){
       ListNode* tmp = cur->next;
       cur->next = pre;
       pre = cur;
       cur = tmp;
     }
     head->next=nullptr;
     return pre;
   }
private:
  void mergeList(ListNode* head1,ListNode* head2){
    ListNode* next1=nullptr,*next2=nullptr;
    while(head1!=nullptr&&head2!=nullptr){
      next1 = head1->next;
      next2 = head2->next;
      head1->next = head2;
      head2->next = next1;
      head1 = next1;
      head2 = next2;
    }
  }
};
