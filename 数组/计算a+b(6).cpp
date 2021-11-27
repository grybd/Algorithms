#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin>>n){
      int sum = 0;
      for(int i=0;i<n;i++){
        int val;
        cin>>val;
        sum+=val;
      }
      cout<<sum<<endl;
    }
}
