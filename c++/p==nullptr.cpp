#include <bits/stdc++.h>
using namespace std;

class A {
private:
  int val;
public:
  A(int _val):val(_val){};
  void printint(){
    std::cout << val <<std::endl;
  }
  void printstr(){
    std::cout<<"abcdefg"<<std::endl;
  }
};

int main(){
  A*p = new A(2);
  p=NULL;
  p->printint();
  p->printstr();
  return 0;
}
