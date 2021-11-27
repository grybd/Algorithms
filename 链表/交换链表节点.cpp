#include <iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
};
class Solution{
public:
  ListNode*cur;
  void reverseNode(ListNode*&head,ListNode*&dummy)
  {
    if(head->next==nullptr) return ;
    reverseNode(head->next,dummy);
    ListNode*temp=dummy->next;
    dummy->next=head->next;
    head->next->next=temp;
    dummy=temp;
    head->next=nullptr;
  }
  ListNode*reverseListNode(ListNode*head){
    ListNode*dummy=head;cur=head;
    reverseNode(head,dummy);
    return cur;
  }
  //递归构建单链表；

  void createListNode(ListNode*&head,int n){
    if(n==0)
    {
      head=nullptr;
      return ;
    }
    ListNode* curA,*curB;
    curA=new ListNode();
    cin>>curA->val;
    //递归构建构建链表；
    createListNode(curB,n-1);
    curA->next=curB;
    //注意这里相当于curB=curA;这样在递回上一层的curA->next=curA(下一层的curA=curB);
    head=curA;
  }
  void printListNode(ListNode*head)
  {
    if(head==nullptr) return;
    cout<<head->val<<'\n';
    printListNode(head->next);
  }

};
int main(){
  Solution s;
  ListNode* head;
  int n;
  cin>>n;
  s.createListNode(head,n);
  s.reverseListNode(head);
  s.printListNode(s.cur);
}
