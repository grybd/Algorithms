#include <vector>
using namespace std;
struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x):val(x),next(nullptr){}
};

class Solution{
public:
  vector<int> res;
  vector<int>reversePrint(ListNode* head){
    if(!head) return res;
    reversePrint(head->next);
    res.push_back(head->val);
    return res;
  }
};
