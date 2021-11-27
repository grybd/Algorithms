#include <iostream>
using namespace std;

void swapn(int&a,int&b)
{
  int temp=a;
   a=b;
   b=temp;
}

int main(){
   int a=1;
   int b=2;
   int c=5;

   swapn(a,b);
   cout<<a;
}
