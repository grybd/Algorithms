#include <bits/stdc++.h>
using namespace std;

struct Node{
  Node* next;
  int val;
};

Node*reverse_nodes(Node*head){
  if(head==nullptr) return head;
  Node* tmp = reverse_nodes(head->next);
  head->next->next = head;
  head->next=nullptr;
  return tmp;
}
