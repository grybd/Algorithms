#include<iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    int len;
    cin>>len;
    int sum=0;
    for(int j=0;j<len;j++){
      int val;
      cin>>val;
      sum+=val;
    }
    cout <<sum << endl;
  }
}
