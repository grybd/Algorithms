#include <queue>
#include <vector>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode():val(0),next(nullptr){}
  ListNode(int x):val(x),next(nullptr){}
  ListNode(int x,ListNode*next):val(x),next(next){}
};

class Solution {
public:
    struct cmp{
      bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
      }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> p;
        for(auto elem:lists){
          if(elem) p.push(elem);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* phead = dummy;
        while(!p.empty()){
          ListNode* tmp = p.top();
          p.pop();
          phead->next = tmp;
          phead = tmp;
          if(tmp->next) p.push(tmp->next);
        }
        ListNode* node = dummy->next;
        delete dummy;
        return node;
    }

    //两两合并
    //先合并两链表
    ListNode* merge(ListNode* p1,ListNode* p2){
      if(!p1) return p2;
      if(!p2) return p1;
      if(p1->val<p2->val){
        p1->next = merge(p1->next,p2);
        return p1;
      }else{
        p2->next = merge(p1,p2->next);
        return p2;
      }
    }
    ListNode* mergeKLists_(vector<ListNode*>&lists){
      ListNode* phead = lists[0];
      for(int i=1;i<(int)lists.size();i++){
        phead = merge(phead,lists[i]);
      }
      return phead;
    }

    //分治思想
    ListNode* mergeKList(vector<ListNode*>&lists){
      if(lists.size()==0) return nullptr;
      return merge(lists,0,lists.size()-1);
    }

    ListNode*merge(vector<ListNode*>&lists,int start,int end){
      if(start==end) return lists[start];
      int mid = start+(end-start)/2;
      ListNode* l1=merge(lists,start,mid);
      ListNode* l2=merge(lists,mid+1,end);
      return merge(l1,l2);
    }
  };
