#include <bits/stdc++.h>
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
};
