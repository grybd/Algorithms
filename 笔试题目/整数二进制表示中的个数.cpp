#include <bits/stdc++.h>
using namespace std;

void bitconut_1(int x){
  cout << x << endl;
  int i=0;
  while (x) {
    x&=x-1;
    i++;
  }
  cout << i << endl;
}

void bitconut_2(int x){
  cout << x << endl;
  int i=0;
  while (x) {
    if(x%2) i++;
    x/=2;
  }
  cout << i << endl;
}

void bitconut_3(int x){
  cout << x << endl;
  int i=0;
  while (x) {
    if(x&1) i++;
    x = x>>1;
  }
  cout << i << endl;
}
