#include <bits/stdc++.h>
using namespace std;

class Singleton{
private:
  Singleton(){
    cout << "Singleton() construct" << endl;
  }
  ~Singleton(){
    cout << "~Singleton() destruct" << endl;
  }
public:
  static Singleton& CreateObject(){
    static Singleton s;
    return s;
  }
  Singleton(Singleton&obj)=delete;
  Singleton operator = (Singleton&obj)=delete;
};
int mian(){
  Singleton& pobj1 = Singleton::CreateObject();
  Singleton& pobj2 = Singleton::CreateObject();
}
