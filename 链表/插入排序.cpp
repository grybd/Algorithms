#include <bits\stdc++.h>
using namespace std;


struct ListNode{
  int val;
  ListNode* next;
  ListNode(int _val): val(_val),next(nullptr){}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head -> next) {return head;}

        ListNode* dummy = new ListNode(INT_MIN);
        dummy -> next = head;
        ListNode* tail = head, *sort = head -> next; // tail指向已排好序部分的尾结点；sort是下一个待排序的结点

        while(sort) {
            if(sort -> val < tail -> val) {
                ListNode* pos = dummy; // 定义一个pos指针，用于每次从头（dummy处）寻找该插入sort的结点的位置。比如1->3，sort是2，那pos就在1处。
                while(pos -> next -> val < sort -> val) {pos = pos -> next;} // 将pos定位到已排好序的且比sort小的部分中的最大的那个结点。
                tail -> next = sort -> next; // 断链。比如dummy->4->2->1->3，tail是4，sort是2，则让4->1，把2拎出来。
                sort -> next = pos -> next; // pos此时在dummy处（因为4大于2），则让 2->4。
                pos -> next = sort; // 上一步相当于断掉了dummy->4，现在重新接起来：dummy->2->4->1->3。
                sort = tail -> next; // 让sort重新回到下一个待排序的结点处
            }
            else {
                tail = tail -> next;
                sort = sort -> next;
            }
        }

        ListNode* res = dummy -> next;
        delete dummy;
        return res;
    }
};
