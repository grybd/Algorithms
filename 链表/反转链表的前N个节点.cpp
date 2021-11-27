#include <iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
};
class Solution{
public:
  ListNode* prev=nullptr;//这部分不能放入递归函数初始化不然会在递归调用过程中覆盖第n+1节点的地址；
  ListNode*reverseListNode_N(ListNode*head,int n)
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
  //迭代法反转链表；
  ListNode* _reverseList_N(ListNode*head,int n)
  {
    if(head==nullptr||n==1) return head;
    ListNode* ptem=nullptr;
    ListNode* first=head;
    ListNode* prev=nullptr;
    ListNode* temp=nullptr;
    while(head!=nullptr&&--n)
    {//找到第i节点的地址
      prev=head->next;
      head->next=ptem;
      ptem=head;
      //cout<<head->next->val<<' ';
      head=prev;
    }
    //由于引入辅助节点所以需要n次调整指针方向，注意while循环里只完成了n-1转换，所以在循环外再补一次；
    temp=prev->next;
    //cout<<prev->val<<' ';
    prev->next=ptem;
    //把头指针指向i+1个节点
    first->next=temp;
    //cout<<prev->val;
    return head;
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
    cout<<head->val<<' ';
    printListNode(head->next);
  }
};

int main(){
  ListNode* head;
  Solution s;
  int n;
  cin>>n;
  s.createListNode(head,n);
  s.printListNode(head);
  return 0;
}
