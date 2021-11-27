#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };
class Solution {
public:
    vector<int>res;
    stack<int>sta;
    vector<int> reversePrint(ListNode* head) {
      if(!head) return res;
      reversePrint(head->next);
      res.push_back(head->val);
      return res;
    }
    //利用栈
    vector<int> reversePrint_(ListNode* head) {
      if(!head) return res;
      reversePrint(head->next);
      res.push_back(head->val);
      return res;
    }  
};
