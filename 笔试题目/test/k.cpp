#include <iostream>
using namespace std;

class Solution{
public:
  int k=0;
  int nums(int n){
    while(n>0)
    {
    if(n%3==0)
    {
      n=n/3;
    }
    else if(n%2==0){
        n=n/2;
        k++;

    }

    else {
      n=n-1;
      k++;
    }
  }
  return k;
}
};
