#include <unordered_map>
#include <iostream>
using namespace std;

struct node{
  int m_key;
  int m_value;
  node* pre;
  node* next;
  node(int key,int val):m_key(key),m_value(val),pre(nullptr),next(nullptr){}
};
class LRUCache{
public:
  LRUCache(int size);
  ~LRUCache();
  void put(int key,int value);
  int get(int key);
  int getSize();
  int getCapacity();
private:
  int m_capacity;
  node* phead;
  node* ptail;
  unordered_map<int,node*>mp;
  void Remove(node* pnode);
  void Sethead(node* pnode);
};
LRUCache::LRUCache(int size){
  this->m_capacity = size;
  this->phead = nullptr;
  this->ptail = nullptr;
}
LRUCache::~LRUCache(){
  auto it = mp.begin();
  while(it!=mp.end()){
    delete it->second;
    it->second = nullptr;
    mp.erase(it++);
  }
}
//往LRUCache的哈希链表头部中插入数据
void LRUCache::Sethead(node* pnode){
  pnode->next = phead;
  pnode->pre = nullptr;
  if(phead!=nullptr){
    phead->pre = pnode;
  }
  phead = pnode;
  if(ptail==nullptr){
    ptail = pnode;
  }
}
//往LRUCache的哈希链表头部中删除元素
void LRUCache::Remove(node* pnode){
  if(pnode==phead){
    phead = phead->next;
    if(phead!=nullptr){
      phead->pre = nullptr;
    }
  }else if(pnode==ptail){
    ptail = ptail->pre;
    if(ptail!=nullptr){
      ptail->next = nullptr;
    }
  }else{
      pnode->pre->next = pnode->next;
      pnode->next->pre = pnode->pre;
    }
  }

//插入数据
void LRUCache::put(int key,int value){
  auto it = mp.find(key);
  if(it==mp.end()){
    node* pnode = new node(key,value);
    Sethead(pnode);
    mp[key] = pnode;
  }else{
    it->second->m_value = value;
    Remove(it->second);
    Sethead(it->second);
  }
  if((int)mp.size()>m_capacity){
    auto it=mp.find(ptail->m_key);
    Remove(it->second);
    delete it->second;
    it->second = nullptr;
    mp.erase(it);
  }
}

//获取数据
int LRUCache::get(int key){
  auto it = mp.find(key);
  if(it!=mp.end()){
    node* pnode = it->second;
    Remove(pnode);
    Sethead(pnode);
    return it->second->m_value;
  }else{
    return -1;
  }
}

int LRUCache::getSize(){
  return mp.size();
}

int LRUCache::getCapacity(){
  return m_capacity;
}
