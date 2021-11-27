#include <bits/stdc++.h>
using namespace std;


struct ListNode {
 	int val;
 	struct ListNode *next;
 	ListNode(int x) : val(x), next(nullptr) {}
 };
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 给定这样一个单链表的头节点 head 和 一个整数 num， 请生成节点值为 num 的新节点，并插入到这个链表中，保证调整后的链表依然有序。返回单链表的新头结点new_head。
     * @param head ListNode类 单链表的头结点head
     * @param num int整型 待插入到链表的一个整数 num
     * @return ListNode类
     */
    ListNode* insertNode(ListNode* head, int num) {
        // write code here
        ListNode* new_num = new ListNode(num);
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode* tmp = head;
        if(!head){
          new_num->next = nullptr;
          return new_num;
        }
        while(head){
          if(num>=dummy->val&&num<=head->val){
            break;
          }
          dummy = dummy->next;
          head = head->next;
        }
        if(head==nullptr){
          dummy->next = new_num;
          new_num->next = nullptr;
          return tmp;
        }
        else if(head==tmp){
          dummy->next = new_num;
          return new_num;
        }
        else{
          dummy->next = new_num;
          new_num->next = head;
          return tmp;
        }
    }
};
