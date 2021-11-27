#include <bits/stdc++.h>
using namespace std;

int main(){
  {
    shared_ptr<int>sh_ptr = make_shared<int>(10);
    cout << sh_ptr.use_count() <<endl;
    weak_ptr<int>wp(sh_ptr);
    cout<< wp.use_count() <<endl;

    if(!wp.expired()){
      shared_ptr<int>sh_ptr2 = wp.lock();
      *sh_ptr = 100;
      cout << wp.use_count()<<endl;
    }
    cout << wp.use_count()<<endl;
  }

}
