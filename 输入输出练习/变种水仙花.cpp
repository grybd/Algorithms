#include <bits/stdc++.h>
using namespace std;

int main(){
  int n = 99999;
  int i,j;
  int a,b,c,d,e,f,g,h;
  int sum = 0;
  for(i=10000;i<=n;++i){
    a = i/10000;
    b = i%10000;
    c = i/1000;
    d = i%1000;
    e = i/100;
    f = i%100;
    g = i/10;
    h = i%10;
    if(a*b+c*d+e*f+g*h==i) cout<<i<<" ";
  }
}
