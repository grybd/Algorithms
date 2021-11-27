#include <bits/stdc++.h>
using namespace std;

struct Node{
  int val;
  void print(int val_){
    val = val_;
  }
};
int main(){
  Node a;
  a.print(2);
  cout << a.val << endl;
}
