#include <iostream>
using namespace std;

int main(){
  int a;
  int sum=0;
  while(cin>>a){
    sum+=a;
    if(cin.get()=='\n'){
      cout<<sum<<endl;
      sum=0;
      continue;
    }
  }
}
