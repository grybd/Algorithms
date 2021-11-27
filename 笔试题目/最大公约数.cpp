#include<iostream>
using namespace std;

int main(){
  int m,n,a,b,r;
  cout << "input two integers:\n";
  cout << "?";cin >>m;
  cout << "?";cin>> n;
  if(m>n){a=m;b=n;}
  else{
    a=n;b=m;
  }
  r = b;
  while(r!=0){
    r = a%b;
    a = b;
    b = r;
  }
  cout << m <<"and" << n << "maximal common divisor is :"<< a << endl;
}
