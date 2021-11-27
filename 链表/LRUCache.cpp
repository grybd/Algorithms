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
  m_capacity = size;
  phead = nullptr;
  ptail = nullptr;
}
LRUCache::~LRUCache(){
  auto it = mp.begin();
  while(it != mp.end()){
    delete it->second;
    it->second = nullptr;
    mp.erase(it++);
  }
}

//插入数据
void LRUCache::put(int key, int value){
  if ((int)mp.size() > m_capacity){
		auto it = mp.find(ptail->m_key);
		Remove(it->second);
		delete it->second;
		it->second = nullptr;
		mp.erase(it);
	}
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
}
//获取数据
int LRUCache::get(int key){
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
int LRUCache::getSize(){
	return mp.size();
}
int LRUCache::getCapacity(){
	return m_capacity;
}
int main(){
	LRUCache mylru(3);
	mylru.put(1, 10);
	mylru.put(3, 20);
	mylru.put(5, 30);
	std::cout << mylru.get(1)<< endl;
	mylru.put(7, 40);
	cout << mylru.get(1) << endl;
	cout << mylru.get(3) << endl;
	cout << mylru.get(5) << endl;
	cout << mylru.get(7) << endl;
	cout << mylru.getSize() << endl;
}
