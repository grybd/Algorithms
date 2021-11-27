#include <bits/stdc++.h>
using namespace std;
class Base {
  public:
    virtual void f() = 0;
};

class D : public Base {
    void f() { std::cout << "D" << std::endl; };
};

int main(){
  D obj;
  memset(&obj, 0, sizeof(obj));
  Base* b = &obj;
  b->f();
}
