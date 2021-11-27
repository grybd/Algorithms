#include <stack>
using namespace std;

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x):val(x),next(NULL){}
};
/*//辅助栈法；
class Solution{
public:
  stack<ListNode*>sta;
  ListNode*reverseList(ListNode*head)
  {
    if(head!=NULL) return NULL;
    while(head!=NULL)
    {
      sta.push(head);
      head=head->next;
    }
    ListNode*temp=sta.top();
    sta.pop();
    ListNode* p=temp;
    int n=sta.size();
    while(n>0)
    {
      ListNode*tem=sta.top();
      sta.pop();
      temp->next=tem;
      temp=temp->next;
      n--;
      if(n==0)temp->next==NULL;
    }
    return p;
  }
};
*/
//迭代法
/*
class Solution{
public:
  ListNode*reverseList(ListNode*head)
  {
    ListNode*cur=NULL,*pre=head;
    while(pre!=NULL)
    {
      ListNode* temp=pre->next;
      pre->next=cur;
      cur=pre;
      pre=temp;
    }
    return cur;
  }
};
*/
//递归法
class Solution{
public:
  ListNode*reverseList(ListNode*head)
  {
    if(head==NULL||head->next==NULL)
    {
      return head;
    }
    ListNode* ret=reverseList(head->next);
    head->next->next=head;
    head->next=NULL;
  }
};
