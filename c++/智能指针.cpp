#include <bits/stdc++.h>
using namespace std;

int main(){
  int a = 10;
  shared_ptr<int> ptra = make_shared<int>(a);
  shared_ptr<int> ptra2(ptra);
  cout << ptra.use_count()<<endl;
  int b = 20;
  int *pb = &a;
  cout << ptra.use_count()<<endl;
  shared_ptr<int>ptrb = make_shared<int>(b);
  cout << ptra.use_count()<<endl;
  ptra2 = ptrb;
  cout << ptra.use_count()<<endl;
  pb = ptrb.get();
  cout<<ptra.use_count()<<endl;
  cout<<ptrb.use_count()<<endl;
}
