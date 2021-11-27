#include <unordered_map>
#include  <iostream>
using namespace std;

struct node{
    int m_key;
    int m_value;
    node* pre;
    node* next;
    node(int key,int value):m_key(key),m_value(value),pre(nullptr),next(nullptr){}
};
class LRU{
public:
    LRU(int size);
    ~LRU();
    void inSert(int key,int value);
    int getValue(int key);
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
LRU::LRU(int size){
  m_capacity = size;
  phead = nullptr;
  ptail = nullptr;
}
LRU::~LRU(){
  auto it = mp.begin();
  while(it != mp.end()){
    delete it->second;
    it->second = nullptr;
    mp.erase(it++);
  }
}
//移除
void LRU::Remove(node *pnode){
	if (pnode == phead){
		phead = phead->next;
		if (phead != nullptr){           //防止只有一个节点Remove出错
			phead->pre = nullptr;
		}
	}
	else if (pnode == ptail){
		ptail = ptail->pre;
		if (ptail != nullptr){
			ptail->next = nullptr;
		}
	}
	else{
		pnode->pre->next = pnode->next;
		pnode->next->pre = pnode->pre;
	}
}
//节点放在头部
void LRU::Sethead(node *pnode){
	pnode->next = phead;
	pnode->pre = nullptr;
	if (phead != nullptr){
		phead->pre = pnode;
	}
	phead = pnode;
	if (ptail == nullptr){
		ptail = pnode;
	}
}
//插入数据
void LRU::inSert(int key, int value){
	auto it = mp.find(key);
	if (it == mp.end()){
		node *pnode = new node(key, value);
		Sethead(pnode);
		mp[key] = pnode;
	}
	else{
		it->second->m_value = value;
		Remove(it->second);
		Sethead(it->second);
	}
	if ((int)mp.size() > m_capacity){
		auto it = mp.find(ptail->m_key);
		Remove(it->second);
		delete it->second;
		it->second = nullptr;
		mp.erase(it);
	}
}
//获取数据
int LRU::getValue(int key){
	auto it = mp.find(key);
	if (it != mp.end()){
		auto no = it->second;
		Remove(no);
		Sethead(no);
		return it->second->m_value;
	}
	else{
		return -1;
	}
}
int LRU::getSize(){
	return mp.size();
}
int LRU::getCapacity(){
	return m_capacity;
}
int main(){
	LRU mylru(3);
	mylru.inSert(1, 10);
	mylru.inSert(3, 20);
	mylru.inSert(5, 30);
	std::cout << mylru.getValue(1)<< endl;
	mylru.inSert(7, 40);
	cout << mylru.getValue(1) << endl;
	cout << mylru.getValue(3) << endl;
	cout << mylru.getValue(5) << endl;
	cout << mylru.getValue(7) << endl;
	cout << mylru.getSize() << endl;
}
