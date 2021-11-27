#include <bits/stdc++.h>
using namespace std;

class Counter{
public:
	Counter():s(0),w(0){};
  int s;
  int w;
};
template<class T>
class weakptr{
private:
  T* _ptr;
  Counter* cnt;
public:
	weakptr(){
    _ptr=0;
    cnt=0;
  }
  weakptr(shared_ptr<T>&s):_ptr(s._ptr),cnt(s.cnt){
    cout<<"w con s"<<endl;
    cnt->w++;
  }
  weakptr(weakptr<T>&w):_ptr(w._ptr),cnt(w.cnt){
    cnt->w++;
  }
  ~weakptr(){
    release();
  }
  weakptr<T>& operator=(weakptr<T>&wk){
    if(this!=&wk){
      release();
      cnt=wk.cnt;
      cnt->w++;
      _ptr = wk._ptr;
    }
    return *this;
  }
  weakptr<T>& operator=(shared_ptr<T>&sh){
    cout<<"w=s"<<endl;
    release();
    cnt=sh.cnt;
    cnt->w++;
    _ptr = sh._ptr;
    return *this;
  }
  shared_ptr<T> lock(){
    return shared_ptr<T>(*this);
  }
  bool expired(){
    if(this->cnt){
      if(cnt->s>0){
        cout<<"empty"<<cnt->s<<endl;
        return false;
      }
    }
    return true;
  }
  void release(){
    if(cnt){
      cnt->w--;
      cout<<"weakptr release"<<cnt->w<<endl;
      if(cnt->w<1&&cnt->w<1){
        cnt = nullptr;
      }
    }
  }
};
