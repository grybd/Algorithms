struct ListNode{
  int val;
  ListNode* next;
  ListNode():val(0),next(nullptr){}
  ListNode(int x):val(x),next(nullptr){}
  ListNode(int x,ListNode*next):val(x),next(next){}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      if(head==nullptr||k==0) return head;
      // 计算有效的 k 值：对于与链表长度成整数倍的「旋转」都是没有意义的（旋转前后链表不变）
      int top = 0;
      auto tmp = head;
      while(tmp!=nullptr&&++top) tmp = tmp->next;
      k%=top;
      if(k==0) return head;
      // 使用「快慢指针」找到倒数第 k 个节点（新头结点）：slow 会停在「新头结点」的「前一位」，也就是「新尾结点」
      auto slow = head,fast = head;
      while(k-->0) fast = fast->next;
      while(fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next;
      }
      auto nHead = slow->next;
      slow->next = nullptr;
      fast->next = head;
      return nHead;
    }
  ListNode* rotateRight_(ListNode* head, int k){
    if(!head) return nullptr;
    int top;
    auto tmp = head;
    while(tmp->next&&++top) tmp = tmp->next;
    //正式成环
    tmp->next = head;
    k = top-(k%top)-1;
    tmp = head;
    while(k--) tmp = tmp->next;
    auto nHead = tmp->next;
    tmp->next = nullptr;
    return nHead;
  }
};
