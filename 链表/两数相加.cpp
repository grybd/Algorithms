#include <bits/stdc++.h>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int _val): val(_val),next(nullptr){}
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* sumHead = new ListNode(-1);
        ListNode* sumNode = sumHead;
        while (l1 != nullptr || l2 != nullptr) {
            // 求和
            int x = l1 != nullptr ? l1->val : 0;
            int y = l2 != nullptr ? l2->val : 0;
            int sum = x + y + carry;
            if (sum >= 10) {
                carry = 1;
                sum = sum - 10;
            } else {
                carry = 0;
            }
            sumNode->next = new ListNode(sum);
            // 三个指针后移
            l1 = l1 != nullptr ? l1->next : nullptr;
            l2 = l2 != nullptr ? l2->next : nullptr;
            sumNode = sumNode->next;
        }
        if (carry != 0) {
            sumNode->next = new ListNode(carry);
        }
        return sumHead->next;
    }
};
