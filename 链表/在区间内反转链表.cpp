#include <iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
};

class Solution{
public:
  ListNode* prev=nullptr;
  ListNode* temp=nullptr;
  ListNode* reverseListNode_N(ListNode*&head,int n)
  {
    if(head==nullptr) return head;
    if(n==1)
    {
      prev = head->next;//找到n+1节点的地址保存起来
      return head;
    }
    ListNode* ret=reverseListNode_N(head->next,n-1);
    head->next->next=head;
    head->next=prev;
    return ret;
  }
  //在某个区间内递归反转链表
  ListNode* reverseListNode_mn(ListNode*&head,int left,int right)
  {
    if(left==1)
    {
        return reverseListNode_N(head,right);
    }
    ListNode* ret=reverseListNode_mn(head->next,left-1,right-1);
    //递归到第m-1==1时使得m-1的节点地址指向ret;
    head->next=ret;
    //为了能让上一层的head->next=head(ret),必须把ret移动到当前层head;
    return head;
  }
  //递归构建单链表；
  void createListNode(ListNode*&head,int n){
    if(n==0)
    {
      head=nullptr;
      return ;
    }
    ListNode* curA;
    curA=new ListNode();
    cin>>curA->val;
    //递归构建构建链表；
    createListNode(head,n-1);
    curA->next=head;
    //注意这里相当于curB=curA;这样在递回上一层的curA->next=curA(下一层的curA=curB);
    head=curA;
  }
  //递归顺序打印单链表的值；
  void printListNode(ListNode*head)
  {
    if(head==nullptr) return;
    cout<<head->val<<' ';
    printListNode(head->next);
  }
//迭代法在某个区间内反转链表
ListNode* _reverseListNode_mn(ListNode*&head,int left,int right){
  ListNode* prev=nullptr,*head_next=nullptr,*temp=head,*first=head;
  ListNode* sec_first=head,*tem=nullptr;
  if(left==right) return head;
  if(left==1)
  {
    while(temp!=nullptr&&--right){
      head_next=temp->next;
      temp->next=prev;
      prev=temp;
      temp=head_next;
    }
    tem=head_next->next;
    head_next->next=prev;
    first->next=tem;
    return temp;
  }
  else{
    int t=left-1;
    while(sec_first!=nullptr&&--t)
    {
      sec_first=sec_first->next;
      //cout<<"o";
    }
    temp=sec_first->next;
    int cha=right-left+1;
    while(temp!=nullptr&&--cha){
      head_next=temp->next;
      temp->next=prev;
      prev=temp;
      temp=head_next;
      //cout<<"h"<<' ';
    }
    tem=head_next->next;
    head_next->next=prev;
    sec_first->next->next=tem;
    sec_first->next=temp;
    return head;
  }
}
};
int main(){
  ListNode* head;
  Solution s;
  int n;
  cin>>n;
  //cin>>b;
  s.createListNode(head,n);
  head=s.reverseListNode_mn(head,2,4);
  cout<<'\n';
  s.printListNode(head);
}
