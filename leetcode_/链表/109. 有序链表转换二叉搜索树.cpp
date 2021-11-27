  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  class Solution {
      public:
         TreeNode* sortedListToBST(ListNode* head) {
          if (head == nullptr) {
              return nullptr;
          }
          if (head->next == nullptr) {
              return new TreeNode(head->val);
          }
          // 快慢指针找中心节点
          ListNode* p = head, *q = head, *pre = nullptr;
          while (q != nullptr && q->next != nullptr) {
              pre = p;
              p = p->next;
              q = q->next->next;
          }
          pre->next = nullptr;
          // 以升序链表的中间元素作为根节点 root，递归的构建 root 的左子树与右子树。
          TreeNode* root = new TreeNode(p->val);
          root->left = sortedListToBST(head);
          root->right = sortedListToBST(p->next);
          return root;
      }
  };
