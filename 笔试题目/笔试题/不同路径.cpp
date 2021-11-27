#include <bits/stdc++.h>
using namespace std;
class image{
  image(image&a){
    if(this!=&a){
      this->ptr = a.ptr;
    }
  }
  image(image&&b){
    this->ptr = b.ptr;
  }
  int* ptr;
};

int main(){

}
